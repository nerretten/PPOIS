#include "FuelingStation.h"
#include "../exceptions.h"
#include <iostream>

FuelingStation::FuelingStation(Car* c, BankAccount* acc, double price)
        : car(c), paymentAccount(acc), fuelPricePerLiter(price), litersFilled(0.0) {}

void FuelingStation::refuel(double liters){
    double totalCost = liters * fuelPricePerLiter;
    try {
        paymentAccount->withdraw(totalCost);
        litersFilled = liters;
        std::cout << "Filled " << liters << " liters at " << fuelPricePerLiter << " per liter. Total: " << totalCost << std::endl;
    } catch (InsufficientFundsException& e) {
        throw e;
    }
}

double FuelingStation::getTotalCost() const {
    return litersFilled * fuelPricePerLiter;
}

std::string FuelingStation::getFuelingDetails() const {
    return "Car: " + car->getVin() + ", Liters: " + std::to_string(litersFilled) + ", Cost: " + std::to_string(getTotalCost());
}