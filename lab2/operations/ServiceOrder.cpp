#include "ServiceOrder.h"
#include <iostream>

ServiceOrder::ServiceOrder(std::string id, Date date)
        : orderId(id), orderDate(date), assignedMechanic(nullptr), status("Pending") {}

void ServiceOrder::addService(Service* service) {
    services.push_back(service);
}

void ServiceOrder::assignMechanic(Mechanic* mech) {
    assignedMechanic = mech;
    if (mech) {
        mech->assignToJob("Service Order " + orderId);
    }
}

void ServiceOrder::complete() {
    status = "Completed";
    if (assignedMechanic) {
        assignedMechanic->completeJob();
    }
    for (Service* s : services) {
        s->perform();
    }
    std::cout << "Service order " << orderId << " completed." << std::endl;
}

void ServiceOrder::printOrder() const {
    std::cout << "=== Service Order ===" << std::endl;
    std::cout << "ID: " << orderId << std::endl;
    std::cout << "Date: " << orderDate.toString() << std::endl;
    std::cout << "Status: " << status << std::endl;
    if (assignedMechanic) {
        std::cout << "Assigned Mechanic: " << assignedMechanic->getName() << std::endl;
    }
    std::cout << "Services:" << std::endl;
    for (const Service* s : services) {
        std::cout << "  - " << s->getDescription() << std::endl;
    }
}

std::string ServiceOrder::getOrderId() const {
    return orderId;
}

std::vector<Service*> ServiceOrder::getServices() const {
    return services;
}

Date ServiceOrder::getDate() const{
    return orderDate;
}