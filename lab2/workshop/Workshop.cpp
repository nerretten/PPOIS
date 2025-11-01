#include "Workshop.h"
#include <iostream>

Workshop::Workshop(std::string name, std::string addr, InventoryManager* inv, AuditLog* log)
        : name(name), address(addr), inventoryManager(inv), auditLog(log) {}

void Workshop::addMechanic(Mechanic* mech) {
    mechanics.push_back(mech);
    std::cout << "Mechanic " << mech->getName() << " added to workshop." << std::endl;
}

void Workshop::createServiceOrder(ServiceOrder* order) {
    activeOrders.push_back(order);
    std::cout << "Service order " << order->getOrderId() << " created." << std::endl;
}

void Workshop::assignOrderToMechanic(ServiceOrder* order, Mechanic* mech) {
    order->assignMechanic(mech);
    std::cout << "Order " << order->getOrderId() << " assigned to mechanic " << mech->getName() << std::endl;
}

void Workshop::completeOrder(ServiceOrder* order) {
    order->complete();
    activeOrders.erase(std::remove(activeOrders.begin(), activeOrders.end(), order), activeOrders.end());
    std::cout << "Order " << order->getOrderId() << " completed and removed from active orders." << std::endl;
}

void Workshop::printStatus() const {
    std::cout << "=== Workshop Status ===" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Mechanics (" << mechanics.size() << "):" << std::endl;
    for (const Mechanic* m : mechanics) {
        std::cout << "  - " << m->getName() << " (" << m->getSpecialty() << ")" << std::endl;
    }
    std::cout << "Active Orders (" << activeOrders.size() << "):" << std::endl;
    for (const ServiceOrder* o : activeOrders) {
        std::cout << "  - " << o->getOrderId() << std::endl;
    }
}

std::string Workshop::getName() const {
    return name;
}