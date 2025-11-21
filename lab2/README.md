Vehicle — Fields: 5 — Methods: 7 — Associations: Engine, Transmission, Wheel, ServiceHistory

Engine — Fields: 3 — Methods: 4 — Associations: Battery, Sensor

Transmission — Fields: 3 — Methods: 3 — Associations: []

Wheel — Fields: 3 — Methods: 3 — Associations: Tire, Brake

Tire — Fields: 3 — Methods: 3 — Associations: []

Brake — Fields: 3 — Methods: 3 — Associations: []

Battery — Fields: 3 — Methods: 3 — Associations: []

Alternator — Fields: 3 — Methods: 3 — Associations: []

Starter — Fields: 3 — Methods: 3 — Associations: []

Radiator — Fields: 3 — Methods: 3 — Associations: []

Thermostat — Fields: 3 — Methods: 3 — Associations: []

CoolingSystem — Fields: 3 — Methods: 3 — Associations: Radiator, Thermostat

FuelSystem — Fields: 3 — Methods: 3 — Associations: []

Exhaust — Fields: 3 — Methods: 3 — Associations: CatalyticConverter

Muffler — Fields: 3 — Methods: 3 — Associations: []

CatalyticConverter — Fields: 3 — Methods: 3 — Associations: []

Sensor — Fields: 3 — Methods: 3 — Associations: []

DiagnosticTool — Fields: 3 — Methods: 3 — Associations: Sensor

Mechanic — Fields: 3 — Methods: 3 — Associations: RepairOrder, WorkItem

RepairOrder — Fields: 3 — Methods: 3 — Associations: WorkItem

WorkItem — Fields: 3 — Methods: 3 — Associations: Part

Part — Fields: 3 — Methods: 2 — Associations: []

Inventory — Fields: 3 — Methods: 3 — Associations: StockItem

Supplier — Fields: 3 — Methods: 3 — Associations: PurchaseOrder, Shipment

PurchaseOrder — Fields: 3 — Methods: 2 — Associations: Shipment

Invoice — Fields: 3 — Methods: 3 — Associations: RepairOrder

Payment — Fields: 3 — Methods: 3 — Associations: []

CashRegister — Fields: 3 — Methods: 3 — Associations: []

CreditCardMachine — Fields: 3 — Methods: 3 — Associations: []

Appointment — Fields: 3 — Methods: 2 — Associations: Bay

Bay — Fields: 3 — Methods: 3 — Associations: Vehicle

Lift — Fields: 3 — Methods: 3 — Associations: []

Garage — Fields: 3 — Methods: 3 — Associations: Bay, Vehicle

Tool — Fields: 3 — Methods: 3 — Associations: []

Toolbox — Fields: 3 — Methods: 3 — Associations: Tool

PaintJob — Fields: 3 — Methods: 3 — Associations: []

Bodywork — Fields: 3 — Methods: 3 — Associations: []

Alignment — Fields: 3 — Methods: 3 — Associations: []

Inspection — Fields: 3 — Methods: 3 — Associations: []

EmissionsTest — Fields: 3 — Methods: 3 — Associations: TestEquipment

TestEquipment — Fields: 3 — Methods: 3 — Associations: []

DeliveryTruck — Fields: 3 — Methods: 3 — Associations: Shipment

Shipment — Fields: 3 — Methods: 3 — Associations: []

StockItem — Fields: 3 — Methods: 3 — Associations: []

Warranty — Fields: 3 — Methods: 3 — Associations: []

Estimate — Fields: 3 — Methods: 3 — Associations: []

Customer — Fields: 3 — Methods: 3 — Associations: Appointment

TechnicianSchedule — Fields: 3 — Methods: 3 — Associations: Mechanic

JobTimer — Fields: 3 — Methods: 4 — Associations: []

ServiceHistory — Fields: 3 — Methods: 3 — Associations: RepairOrder

Всего полей: 152 Всего методов: 147 Всего ассоциаций: 31 Исключений: 12
