#include "UnitTest++.h"

#include "customer/Appointment.h"
#include "customer/Customer.h"
#include "customer/Warranty.h"

#include "exceptions/CorrodedConnectorException.h"
#include "exceptions/DiagnosticFailureException.h"
#include "exceptions/InsufficientStockException.h"
#include "exceptions/InvalidAppointmentException.h"
#include "exceptions/InvalidVINException.h"
#include "exceptions/LiftOverloadException.h"
#include "exceptions/MechanicNotAvailableException.h"
#include "exceptions/PartNotFoundException.h"
#include "exceptions/PaymentDeclinedException.h"
#include "exceptions/SensorFailureException.h"
#include "exceptions/WarrantyExpiredException.h"
#include "exceptions/WorkshopException.h"

#include "finance/CashRegister.h"
#include "finance/CreditCardMachine.h"
#include "finance/Invoice.h"
#include "finance/Payment.h"

#include "inventory/DeliveryTruck.h"
#include "inventory/Inventory.h"
#include "inventory/Part.h"
#include "inventory/PurchaseOrder.h"
#include "inventory/Shipment.h"
#include "inventory/StockItem.h"
#include "inventory/Supplier.h"

#include "service/Alignment.h"
#include "service/Estimate.h"
#include "service/Inspection.h"
#include "service/JobTimer.h"
#include "service/PaintJob.h"
#include "service/RepairOrder.h"
#include "service/ServiceHistory.h"
#include "service/WorkItem.h"

#include "tools/DiagnosticTool.h"
#include "tools/EmissionsTest.h"
#include "tools/Lift.h"
#include "tools/TestEquipment.h"
#include "tools/Tool.h"
#include "tools/Toolbox.h"

#include "vehicle/Alternator.h"
#include "vehicle/Battery.h"
#include "vehicle/Bodywork.h"
#include "vehicle/Brake.h"
#include "vehicle/CatalyticConverter.h"
#include "vehicle/CoolingSystem.h"
#include "vehicle/Engine.h"
#include "vehicle/Exhaust.h"
#include "vehicle/FuelSystem.h"
#include "vehicle/Muffler.h"
#include "vehicle/Radiator.h"
#include "vehicle/Sensor.h"
#include "vehicle/Starter.h"
#include "vehicle/Thermostat.h"
#include "vehicle/Tire.h"
#include "vehicle/Transmission.h"
#include "vehicle/Vehicle.h"
#include "vehicle/Wheel.h"

#include "workshop/Bay.h"
#include "workshop/Garage.h"
#include "workshop/Mechanic.h"
#include "workshop/TechnicianSchedule.h"

#define CHECK_THROWS(E, expr) \
    CHECK_THROW(expr, E)

using namespace std;

TEST(BatteryTest) {
    Battery b(50.0, 0.8, 12);
            CHECK(b.provideStartCurrent(200.0) == false);
    b.charge(1.0, 5.0);
            CHECK_CLOSE(0.9, b.health(), 0.1);
}

TEST(EngineStartTest) {
    Battery* bat = new Battery(60.0, 0.9, 6);
    Engine eng(4, 2.0, bat);
            CHECK(eng.start() == false);
    delete bat;
}

TEST(EngineFuelConsumptionTest) {
    Battery* bat = new Battery(60.0, 0.9, 6);
    Engine eng(4, 2.0, bat);
    double fuel = eng.computeFuelConsumption(1.0, 2000.0);
            CHECK_CLOSE(0.3, fuel, 0.01);
    delete bat;
}

TEST(TireWearTest) {
    Tire t("ModelX", 2.3, 8);
    t.wearAfterKm(20000);
            CHECK(t.needsReplacement() == false);
}

TEST(TireReplacementNeeded) {
    Tire t("ModelX", 2.0, 1);
            CHECK(t.needsReplacement() == true);
}

TEST(InventoryReserveSuccess) {
    StockItem* item = new StockItem("SKU-123", 10, 20.0);
    Inventory inv(1, 100.0);
    inv.addStock(item);
    inv.reserve("SKU-123", 3);
            CHECK_EQUAL(7, item->getQuantity());
}

TEST(InventoryReserveNotFound) {
    Inventory inv(1, 100.0);
    CHECK_THROWS(PartNotFoundException, inv.reserve("SKU-999", 1));
}

TEST(InventoryInsufficientStock) {
    StockItem* item = new StockItem("SKU-123", 2, 20.0);
    Inventory inv(1, 100.0);
    inv.addStock(item);
    CHECK_THROWS(InsufficientStockException, inv.reserve("SKU-123", 5));
}

TEST(InventoryAvailable) {
    StockItem* item = new StockItem("SKU-123", 5, 20.0);
    Inventory inv(1, 100.0);
    inv.addStock(item);
            CHECK_EQUAL(5, inv.available("SKU-123"));
            CHECK_EQUAL(0, inv.available("SKU-999"));
}

TEST(PaymentCashSuccess) {
    Payment p(100.0, "cash");
    p.processCash();
            CHECK(p.isConfirmed() == true);
}

TEST(PaymentCardSuccess) {
    Payment p(500.0, "card");
    p.processCard("1234567890123456");
            CHECK(p.isConfirmed() == true);
}

TEST(PaymentCardDeclined) {
    Payment p(15000.0, "card");
    CHECK_THROWS(PaymentDeclinedException, p.processCard("1234"));
}

TEST(CreditCardMachineOnlineAuthSuccess) {
    CreditCardMachine term("TERM-01", true, 0);
            CHECK(term.authorize("1234567890123456", 200.0) == true);
            CHECK_EQUAL(200, term.lastCode());
}

TEST(CreditCardMachineOfflineDecline) {
    CreditCardMachine term("TERM-01", false, 0);
    CHECK_THROWS(PaymentDeclinedException, term.authorize("1234", 100.0));
}

TEST(WarrantyValid) {
    Warranty w("Standard", 24, true);
            CHECK(w.validate(12) == true);
}

TEST(WarrantyExpired) {
    Warranty w("Standard", 12, true);
    CHECK_THROWS(WarrantyExpiredException, w.validate(15));
}

TEST(WarrantyRefund) {
    Warranty w("Standard", 12, true);
            CHECK_CLOSE(0.25, w.prorateRefund(9), 0.01);
}

TEST(DiagnosticToolConnectedSuccess) {
    Sensor s("temp", 80.0, true);
    DiagnosticTool dt("DT-200", true);
    auto codes = dt.scanAll(&s);
            CHECK(codes.empty());
}

TEST(DiagnosticToolDisconnectedFailure) {
    Sensor s("temp", 80.0, true);
    DiagnosticTool dt("DT-200", false);
    CHECK_THROWS(DiagnosticFailureException, dt.scanAll(&s));
}

TEST(DiagnosticToolSensorFailure) {
    Sensor s("temp", 80.0, false);
    DiagnosticTool dt("DT-200", true);
    auto codes = dt.scanAll(&s);
            CHECK(!codes.empty());
            CHECK_EQUAL("SENSOR_ERR", codes[0]);
}

TEST(VehicleRunEngine) {
    Battery* bat = new Battery(60.0, 0.9, 6);
    Engine* eng = new Engine(4, 2.0, bat);
    Transmission* trans = new Transmission(6, true, 0.8);
    Vehicle v("VIN123456789", eng, trans);

    double fuel = v.runEngineFor(1.0);
            CHECK_CLOSE(0.3, fuel, 0.01);

    delete trans;
    delete eng;
    delete bat;
}

TEST(VehicleVIN) {
    Battery* bat = new Battery(60.0, 0.9, 6);
    Engine* eng = new Engine(4, 2.0, bat);
    Transmission* trans = new Transmission(6, true, 0.8);
    Vehicle v("VIN123", eng, trans);
            CHECK_EQUAL("VIN123", v.getVIN());
    delete trans; delete eng; delete bat;
}

TEST(LiftNormalOperation) {
    Lift lift(2000.0, 1500.0, "down");
            CHECK(lift.safetyCheck() == true);
    lift.liftVehicle(nullptr);
            CHECK_EQUAL("up", lift.getState());
}

TEST(LiftOverloadException) {
    Lift lift(1000.0, 1200.0, "down");
    CHECK_THROWS(LiftOverloadException, lift.liftVehicle(nullptr));
}

TEST(ToolboxFindTool) {
    Tool* t1 = new Tool("Wrench", true, 5);
    Tool* t2 = new Tool("Socket", false, 10);
    Toolbox box(101, "Bay3");
    box.addTool(t1);
    box.addTool(t2);

    Tool* found = box.findTool("Socket");
            CHECK(found != nullptr);
            CHECK_EQUAL("Socket", found->getName());

            CHECK(box.findTool("Hammer") == nullptr);

    delete t1; delete t2;
}

TEST(ServiceHistoryAddsOrder) {
    ServiceHistory hist;
    RepairOrder* order = new RepairOrder(1001);
    Part* part = new Part("P-001", "Filter", 20.0);
    WorkItem* wi = new WorkItem("Change oil", part, 0.5);
    order->addWorkItem(wi);

    hist.addOrder(order);
            CHECK_EQUAL(1, hist.count());
            CHECK_CLOSE(36, hist.averageCost(), 1.0);

    delete wi; delete part; delete order;
}

TEST(ExceptionsAreDerivable) {
            CHECK_THROW(throw PartNotFoundException(), PartNotFoundException);
            CHECK_THROW(throw InsufficientStockException(), InsufficientStockException);
            CHECK_THROW(throw PaymentDeclinedException(), PaymentDeclinedException);
            CHECK_THROW(throw InvalidVINException(), InvalidVINException);
            CHECK_THROW(throw MechanicNotAvailableException(), MechanicNotAvailableException);
            CHECK_THROW(throw LiftOverloadException(), LiftOverloadException);
            CHECK_THROW(throw DiagnosticFailureException(), DiagnosticFailureException);
            CHECK_THROW(throw SensorFailureException(), SensorFailureException);
            CHECK_THROW(throw CorrodedConnectorException(), CorrodedConnectorException);
            CHECK_THROW(throw WarrantyExpiredException(), WarrantyExpiredException);
            CHECK_THROW(throw InvalidAppointmentException(), InvalidAppointmentException);
}

TEST(StockItemTemperatureOK) {
    StockItem item("SKU-A", 5, 25.0);
            CHECK(item.checkTemperature() == true);
}

TEST(StockItemTemperatureFail) {
    StockItem item("SKU-B", 5, -5.0);
            CHECK(item.checkTemperature() == false);
}

TEST(FuelSystemRangeEstimate) {
    FuelSystem fs(60.0, 30.0, 4);
    double range = fs.estimateRange(8.0);
            CHECK_CLOSE(375.0, range, 1.0);
}

TEST(EmissionsPassStandard) {
    TestEquipment eq("EQ-1", true, 100);
    EmissionsTest test(0.3, 40.0, &eq);
            CHECK(test.passStandard() == true);
}

TEST(EmissionsFailStandard) {
    TestEquipment eq("EQ-1", true, 100);
    EmissionsTest test(0.6, 60.0, &eq);
            CHECK(test.passStandard() == false);
}

TEST(AlignmentAdjustToe) {
    Alignment align(0.1, 0.5, 3.0);
    align.adjustToe(0.15);
            CHECK_CLOSE(0.15, align.getToeFront(), 0.001);
}

TEST(JobTimerStartStop) {
    JobTimer timer(0, false, 0);
    timer.start();
            CHECK(timer.getRunning() == true);
    timer.stop();
            CHECK(timer.getRunning() == false);
}

TEST(CustomerContactCard) {
    Appointment* appt = new Appointment("2025-11-25 10:00", nullptr, 60);
    Customer cust("Alice", "+123", appt);
            CHECK_EQUAL("Alice:+123", cust.contactCard());
    delete appt;
}

TEST(FullRepairWorkflow) {
    Part* oilFilter = new Part("FIL-01", "Oil Filter", 15.0);
    StockItem* stock = new StockItem("FIL-01", 5, 20.0);
    Inventory* inv = new Inventory(10, 200.0);
    inv->addStock(stock);

    inv->reserve("FIL-01", 1);
            CHECK_EQUAL(4, stock->getQuantity());

    WorkItem* wi = new WorkItem("Oil change", oilFilter, 0.75);
    RepairOrder* order = new RepairOrder(2001);
    order->addWorkItem(wi);

    Invoice invoice(5001, order);
            CHECK_CLOSE(36.75, invoice.calculateTotal(), 0.01);

    Payment pay(invoice.calculateTotal(), "cash");
    pay.processCash();
            CHECK(pay.isConfirmed());

    delete wi; delete oilFilter; delete stock; delete inv; delete order;
}

TEST(CashRegisterTest) {
    CashRegister reg(100.0, "Front Desk");
    reg.openDrawer();
    reg.registerTransaction(50.0);
    reg.closeDrawer();
}

TEST(DeliveryTruckTest) {
    Shipment* ship = new Shipment("TRK123", 10, 50.0);
    DeliveryTruck truck("ABC123", 20.0, ship);
            CHECK_CLOSE(0.5, truck.estimateETA(30.0), 0.01);

    Shipment* newShip = new Shipment("TRK124", 5, 25.0);
    truck.load(newShip);
    truck.deliver();
    delete ship;
    delete newShip;
}

TEST(ShipmentTest) {
    Shipment s("SHP001", 4, 20.0);
    s.track();
            CHECK_CLOSE(5.0, s.averageItemWeight(), 0.01);
    s.receive();
            CHECK_EQUAL(0, s.getItemsount());
}

TEST(PurchaseOrderTest) {
    PurchaseOrder po("SKU-777", 100);
            CHECK_CLOSE(1500.0, po.expectedCost(15.0), 0.01);
    Shipment* s = new Shipment("SHIP999", 100, 80.0);
    po.markReceived(s);
    delete s;
}

TEST(SupplierTest) {
    Supplier sup("AutoParts Inc", "contact@auto.com", 3);
            CHECK(sup.checkLeadTime(5) == true);
            CHECK(sup.checkLeadTime(2) == false);

    PurchaseOrder* po = sup.makeOrder("FILTER-01", 10);
            CHECK_EQUAL(10, po->getQuantity());
    delete po;
}

TEST(AlternatorTest) {
    Alternator alt(50.0, 0.9, true);
            CHECK_CLOSE(45.0, alt.generate(1000), 0.01);
    alt.adjustBelt(0.8);
            CHECK(alt.testOutput() == true);

    Alternator bad(0, 0, false);
            CHECK(bad.testOutput() == false);
}

TEST(BrakeTest) {
    Brake b(5.0, 0.9, true);
            CHECK(b.checkPads() == true);
            CHECK_CLOSE(4.5, b.apply(10.0), 0.1);
    b.bleed(0.2);
}

TEST(BodyworkTest) {
    Bodywork bw("dent", 4.0, 2.0);
    bw.straighten();
            CHECK_CLOSE(3.2, bw.getHoursNeeded(), 0.01);
    bw.weld(1.5);
    bw.estimateMaterial();
}

TEST(CoolingSystemTest) {
    Radiator* rad = new Radiator(5.0, 0.95, true);
    Thermostat* thermo = new Thermostat(90.0, 80.0, 100);
    CoolingSystem cs(rad, thermo, 2.0);
    cs.flushAll();
            CHECK(cs.checkLeaks() == true);
    double cool = cs.regulate(95.0);
            CHECK(cool > 0);
    delete rad; delete thermo;
}

TEST(BayTest) {
    Bay bay("Bay-5");
            CHECK(bay.isOccupied() == false);
    Vehicle* v = new Vehicle("VIN999",
                             new Engine(4, 2.0, new Battery(60, 0.9, 12)),
                             new Transmission(6, true, 0.9)
    );
    bay.assignVehicle(v);
            CHECK(bay.isOccupied() == true);
    bay.releaseVehicle();
            CHECK(bay.isOccupied() == false);
    delete v;
}

TEST(MechanicTest) {
    Mechanic m("John", 5, true);
            CHECK_CLOSE(0, m.estimateTimeFor(nullptr), 0.01);
}

TEST(TechnicianScheduleTest) {
    Mechanic* m = new Mechanic("Alice", 3, true);
    TechnicianSchedule sched(m, "09:00", "17:00");
            CHECK(sched.isOnShift("12:00") == true);
    TechnicianSchedule other(m, "08:00", "16:00");
    sched.swapShift(&other);
    sched.extendShift(30);
    delete m;
}

TEST(EstimateTest) {
    Estimate e(101, "Brake replacement", 1.5);
            CHECK_CLOSE(150.0, e.totalEstimate(100.0), 0.01);
    e.addLabor(0.5);
            CHECK_CLOSE(2.0, e.getLabourHours(), 0.01);
    e.reduce(10.0);
            CHECK_CLOSE(1.8, e.getLabourHours(), 0.01);
}

TEST(PaintJobTest) {
    PaintJob pj("Red", 5.0, false);
            CHECK_CLOSE(5.0 * 30.0 + 80.0, pj.estimateCost(), 0.01);
    pj.applyPrimer();
    pj.paintLayer();
            CHECK_CLOSE(4.7, pj.getLiters(), 0.01);
}

TEST(InspectionTest) {
    Inspection ins("Bob", true, 0);
    ins.run();
            CHECK_EQUAL("OK", ins.report());
    ins.failWith(3);
            CHECK_EQUAL("ISSUES", ins.report());
}

TEST(ExhaustTest) {
    CatalyticConverter* cat = new CatalyticConverter(0.8, 400, 20);
    Exhaust ex(3.0, 0.1, cat);
            CHECK_CLOSE(3.0 + 0.2, ex.soundLevel(300), 0.1);
    ex.replaceSection(0.5);
            CHECK_CLOSE(2.5, ex.getLength(), 0.01);
    delete cat;
}

TEST(MufflerTest) {
    Muffler m(20.0, false, 12);
            CHECK(m.needsService() == true);
    m.addBaffle();
            CHECK_CLOSE(22.0, m.getAttenuationDb(), 0.01);
            CHECK(m.reduceNoise(80.0) == 58.0);
}

TEST(CatalyticConverterTest) {
    CatalyticConverter c(0.7, 500, 40);
            CHECK(c.checkEfficiency() == true);
    c.setSootlevel(60);
            CHECK(c.checkEfficiency() == false);
    c.clean();
            CHECK_EQUAL(30, c.getSootlevel());
            CHECK_CLOSE(5.6, c.expectedLifetimeYears(), 0.01);
}

TEST(RadiatorTest) {
    Radiator r(6.0, 0.8, true);
            CHECK_CLOSE(4.0, r.coolRate(1.0), 0.1);
    r.flush();
    r.leakTest();
}

TEST(ThermostatTest) {
    Thermostat t(90, 85, 500);
            CHECK(t.shouldOpen() == false);
    t.operate(95);
            CHECK(t.shouldOpen() == true);
            CHECK_CLOSE(0.05, t.estimateFailureProb(), 0.01);
}

TEST(StarterTest) {
    Starter s(200, 5000, true);
            CHECK(s.crank() == true);
    s.setSycles(9999);
            CHECK(s.crank() == true);
    s.setSycles(10000);
            CHECK(s.crank() == true);
    s.service();
            CHECK(s.crank() == true);
            CHECK_CLOSE(1.0, s.expectedLifeLeft(), 0.01);
}

TEST(WheelTest) {
    Tire* t = new Tire("AllSeason", 2.3, 8);
    Brake* b = new Brake(6.0, 0.95, true);
    Wheel w(t, b);
    w.rotate(1200);
            CHECK_CLOSE(1200 / 60.0 * 2 * 3.1416 * 0.3 * 3.6, w.getSpeedKmh(0.3), 1.0);
    Tire* newTire = new Tire("Winter", 2.5, 7);
    w.replaceTire(newTire);
    delete t; delete b; delete newTire;
}

TEST(TransmissionTest) {
    Transmission trans(6, false, 0.5);
            CHECK(trans.shiftUp() == true);
    Transmission lowFluid(6, false, 0.1);
            CHECK(lowFluid.shiftUp() == false);
            CHECK_CLOSE(0.05, lowFluid.leakRate(), 0.01);
}


TEST(VehicleRunEngineLogsToHistory) {
    ServiceHistory hist;
    Battery* bat = new Battery(60.0, 0.9, 12);
    Engine* eng = new Engine(4, 2.0, bat);
    Transmission* trans = new Transmission(6, true, 0.8);
    Vehicle v("VIN-TEST", eng, trans);
    v.recordService(&hist);

    double fuel = v.runEngineFor(1.0);
            CHECK_CLOSE(0.3, fuel, 0.01);
            CHECK_EQUAL(1, hist.count());
            CHECK_CLOSE(0.0, hist.averageCost(), 0.01);

    delete trans; delete eng; delete bat;
}


TEST(ToolDecalibratesAfter50Uses) {
    Tool wrench("Torque Wrench", true, 48);
            CHECK(wrench.needsCalibration() == false);

    wrench.useFor("Job 1");
    wrench.useFor("Job 2");

            CHECK(wrench.needsCalibration() == true);

    wrench.calibrate();
            CHECK(wrench.needsCalibration() == false);
}


TEST(ToolboxInventoryDoesNotCrash) {
    Toolbox box(201, "Bay 5");
    box.addTool(new Tool("Socket", true, 10));
    box.addTool(new Tool("Wrench", false, 60));

    box.inventory();

    for (auto* t : box.getTools()) delete t;
}

TEST(GarageOpenCloseManagesBays) {
    Garage g(2, "Test St");
    Bay* b0 = g.getBays()[0];
    Bay* b1 = g.getBays()[1];

    Vehicle v("VIN-G", nullptr, nullptr);
    g.parkVehicle(b0, &v);
            CHECK(b0->isOccupied() == true);

    g.close(); // should release all
            CHECK(b0->isOccupied() == false);
            CHECK(b1->isOccupied() == false);

    g.open(); // just ensure no crash
}

TEST(MechanicPerformRepairRequiresCert) {
    Mechanic uncert("Bob", 3, false);
    RepairOrder* order = new RepairOrder(999);
            CHECK_THROW(uncert.performRepair(order), std::runtime_error);

    Mechanic cert("Alice", 5, true);
    cert.performRepair(order);
    delete order;
}

TEST(TechnicianScheduleIsOnShiftRealLogic) {
    Mechanic m("Test", 1, true);
    TechnicianSchedule sched(&m, "09:00", "17:00");

            CHECK(sched.isOnShift("08:59") == false);
            CHECK(sched.isOnShift("09:00") == true);
            CHECK(sched.isOnShift("12:30") == true);
            CHECK(sched.isOnShift("17:00") == true);
            CHECK(sched.isOnShift("17:01") == false);
}

TEST(InvoiceApplyPaymentFullFlow) {
    Part* p = new Part("FILTER", "Oil Filter", 100.0);
    WorkItem* wi = new WorkItem("Change", p, 1.0);
    RepairOrder* order = new RepairOrder(111);
    order->addWorkItem(wi);

    Invoice inv(500, order);
            CHECK_CLOSE(145.0, inv.calculateTotal(), 0.01); // 100*1.2 + 25

    inv.applyPayment(100.0);
            CHECK_EQUAL(false, inv.isPaid());

    inv.applyPayment(45.0);
            CHECK_EQUAL(true, inv.isPaid());

    delete wi; delete p; delete order;
}


TEST(CashRegisterRejectsNonPositiveAmount) {
    CashRegister reg(100.0, "Front");
    reg.registerTransaction(10.0);
    CHECK_THROW(reg.registerTransaction(-5.0), std::invalid_argument);
    CHECK_THROW(reg.registerTransaction(0.0), std::invalid_argument);
}


TEST(DiagnosticToolO2SensorScan) {
    Sensor o2("O2", 0.05, true);
    DiagnosticTool tool("DT-PRO", true);

    auto codes = tool.scanAll(&o2);
            CHECK(!codes.empty());
            CHECK_EQUAL("P0171", codes[0]); // lean mixture

            CHECK(tool.hasActiveCodes() == true);
    tool.clearCodes();
            CHECK(tool.hasActiveCodes() == false);
}

TEST(PurchaseOrderRejectsInsufficientShipment) {
    PurchaseOrder po("PART-123", 10);
    Shipment* small = new Shipment("T1", 5, 30.0); // only 5 items

            CHECK_THROW(po.markReceived(small), InsufficientStockException);

    Shipment* large = new Shipment("T2", 12, 72.0);
    po.markReceived(large);
            CHECK_EQUAL(true, po.isReceived());

    delete small; delete large;
}


TEST(TestEquipmentConstructor) {
    TestEquipment eq("EQ-123", true, 100);
            CHECK_EQUAL("EQ-123", eq.getSerial());
            CHECK_EQUAL(true, eq.isCalibrated());
            CHECK_EQUAL(100, eq.getLastCalibrationDays());
}

TEST(TestEquipmentNeedsCalibrationWhenNotCalibrated) {
    TestEquipment eq("EQ-001", false, 0);
            CHECK(eq.needsCalibration() == true);
}

TEST(TestEquipmentNeedsCalibrationWhenOverdue) {
    TestEquipment eq("EQ-002", true, 400);
            CHECK(eq.needsCalibration() == true);
}

TEST(TestEquipmentDoesNotNeedCalibrationWhenFresh) {
    TestEquipment eq("EQ-003", true, 200);
            CHECK(eq.needsCalibration() == false);
}

TEST(TestEquipmentCalibrateResetsState) {
    TestEquipment eq("EQ-004", false, 500);
            CHECK(eq.needsCalibration() == true);

    eq.calibrate();
            CHECK(eq.needsCalibration() == false);
}

TEST(TestEquipmentMeasureReturnsConstant) {
    TestEquipment eq("EQ-005", true, 0);
            CHECK_CLOSE(42.0, eq.measure(), 0.001);
}

Vehicle* createDummyVehicle() {
    Battery* bat = new Battery(60.0, 0.9, 12);
    Engine* eng = new Engine(4, 2.0, bat);
    Transmission* trans = new Transmission(6, true, 0.8);
    return new Vehicle("VIN-DUMMY", eng, trans);
}

TEST(CustomerContactCardReturnsCorrectFormat) {
    Appointment* appt = new Appointment("2025-11-25 10:00", nullptr, 60);
    Customer cust("Ivan", "+375291234567", appt);
            CHECK_EQUAL("Ivan:+375291234567", cust.contactCard());
    delete appt;
}

TEST(CustomerRequestServiceCreatesOrderAndLogs) {
    Appointment* appt = new Appointment("2025-11-25 10:00", nullptr, 60);
    Customer cust("Anna", "+375297654321", appt);
    cust.requestService("Oil change and filter replacement");
    delete appt;
}

TEST(CustomerCancelAppointmentWithNullDoesNothing) {
    Customer cust("NoAppt", "123", nullptr);
    cust.cancelAppointment();
}

TEST(CustomerCancelAppointmentReleasesBayIfOccupied) {
    Bay* bay = new Bay("TestBay");
    Appointment* appt = new Appointment("2025-11-25 10:00", bay, 60);
    Customer cust("Petr", "456", appt);

    Vehicle* v = createDummyVehicle();
    bay->assignVehicle(v);
            CHECK(bay->isOccupied() == true);

    cust.cancelAppointment();
            CHECK(bay->isOccupied() == false);

    delete v;
    delete bay;
}

TEST(CustomerCancelAppointmentDoesNotReleaseEmptyBay) {
    Bay* bay = new Bay("EmptyBay");
    Appointment* appt = new Appointment("2025-11-25 10:00", bay, 60);
    Customer cust("Maria", "789", appt);
            CHECK(bay->isOccupied() == false);

    cust.cancelAppointment();
            CHECK(bay->isOccupied() == false);

    delete bay;
}

int main() {
    return UnitTest::RunAllTests();
}