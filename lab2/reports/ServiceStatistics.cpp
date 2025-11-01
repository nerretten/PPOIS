#include "ServiceStatistics.h"
#include <iostream>

ServiceStatistics::ServiceStatistics(std::vector<ServiceOrder*> ord)
        : orders(ord), totalServices(0), averageCost(0.0) {}

void ServiceStatistics::computeStats() {
    totalServices = orders.size();
    double totalCost = 0.0;
    for (ServiceOrder* o : orders) {
        totalCost += o->getServices().size() * 100.0;
    }
    averageCost = totalServices > 0 ? totalCost / totalServices : 0.0;
}

int ServiceStatistics::getTotalServices() const {
    return totalServices;
}

double ServiceStatistics::getAverageCost() const {
    return averageCost;
}

void ServiceStatistics::printStats() const {
    std::cout << "=== Service Statistics ===" << std::endl;
    std::cout << "Total Services: " << totalServices << std::endl;
    std::cout << "Average Cost per Service: " << averageCost << std::endl;
}