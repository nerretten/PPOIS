#include "ServiceSchedule.h"
#include <iostream>

ServiceSchedule::ServiceSchedule(Date start, Date end)
        : startDate(start), endDate(end) {}

void ServiceSchedule::addOrder(ServiceOrder* order) {
    scheduledOrders.push_back(order);
    std::cout << "Order " << order->getOrderId() << " added to schedule." << std::endl;
}

void ServiceSchedule::removeOrder(ServiceOrder* order) {
    scheduledOrders.erase(std::remove(scheduledOrders.begin(), scheduledOrders.end(), order), scheduledOrders.end());
    std::cout << "Order " << order->getOrderId() << " removed from schedule." << std::endl;
}

void ServiceSchedule::printSchedule() const {
    std::cout << "=== Service Schedule ===" << std::endl;
    std::cout << "From: " << startDate.toString() << " To: " << endDate.toString() << std::endl;
    for (const ServiceOrder* o : scheduledOrders) {
        std::cout << "  - Order " << o->getOrderId() << std::endl;
    }
}

std::vector<ServiceOrder*> ServiceSchedule::getOrdersForDate(Date date) const {
    std::vector<ServiceOrder*> result;
    for (ServiceOrder* o : scheduledOrders) {
        if(o->getDate() == date)
            result.push_back(o);
    }
    return result;
}