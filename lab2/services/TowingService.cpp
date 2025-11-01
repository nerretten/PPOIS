#include "TowingService.h"
#include <iostream>

TowingService::TowingService(Car* car, std::string request, std::string dest, double price)
        : towedCar(car), requesterName(request), destination(dest), cost(price), isCompleted(false) {}

void TowingService::dispatch() {
    std::cout << "Towing service dispatched for car " << towedCar->getVin() << " to " << destination << std::endl;
}

void TowingService::complete() {
    isCompleted = true;
    std::cout << "Towing service completed for car " << towedCar->getVin() << std::endl;
}

double TowingService::getCost() const {
    return cost;
}

std::string TowingService::getDestination() const {
    return destination;
}