#include "Customer.h"



Customer::Customer(const std::string &n, const std::string &p, Appointment* a)
        : name(n), phone(p), nextAppointment(a) {}

void Customer::requestService(const std::string &desc) {
    static int orderId = 1000;
    RepairOrder* order = new RepairOrder(orderId++);

    WorkItem* item = new WorkItem(desc, nullptr, 1.0);
    order->addWorkItem(item);

    std::cout << "[Service Request] Customer " << name
              << " requested: \"" << desc << "\" (Order #" << orderId - 1 << ")" << std::endl;

}

void Customer::cancelAppointment() {
    if (nextAppointment != nullptr) {
        Bay* bay = nextAppointment->getBay();
        if (bay && bay->isOccupied()) {
            bay->releaseVehicle();
        }
        nextAppointment = nullptr;
    }
}

std::string Customer::contactCard() const {
    return name + ":" + phone;
}