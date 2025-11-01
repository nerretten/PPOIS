#include "MaintenancePlan.h"
#include <iostream>

MaintenancePlan::MaintenancePlan(Car* c, Date next, std::vector<std::string> services, double cost)
        : car(c), nextServiceDate(next), scheduledServices(services), estimatedCost(cost) {}

void MaintenancePlan::addService(std::string service) {
    scheduledServices.push_back(service);
    std::cout << "Added service '" << service << "' to maintenance plan for car " << car->getVin() << std::endl;
}

void MaintenancePlan::updateNextServiceDate(Date newDate) {
    nextServiceDate = newDate;
    std::cout << "Next service date updated to " << newDate.toString() << " for car " << car->getVin() << std::endl;
}

void MaintenancePlan::printPlan() const {
    std::cout << "=== Maintenance Plan for Car " << car->getVin() << " ===" << std::endl;
    std::cout << "Next Service Date: " << nextServiceDate.toString() << std::endl;
    std::cout << "Scheduled Services:" << std::endl;
    for (const std::string& s : scheduledServices) {
        std::cout << "  - " << s << std::endl;
    }
    std::cout << "Estimated Cost: " << estimatedCost << std::endl;
}

std::string MaintenancePlan::getCarVin() const {
    return car->getVin();
}

Date MaintenancePlan::getNextServiceDate() const {
    return nextServiceDate;
}