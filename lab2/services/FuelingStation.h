#ifndef FUELINGSTATION_H
#define FUELINGSTATION_H

#include "../core/Car.h"
#include "../finance/BankAccount.h"
#include <string>

class FuelingStation {
private:
    Car* car;
    BankAccount* paymentAccount;
    double fuelPricePerLiter;
    double litersFilled;

public:
    FuelingStation(Car* c, BankAccount* acc, double price);
    void refuel(double liters);
    double getTotalCost() const;
    std::string getFuelingDetails() const;
};

#endif // FUELINGSTATION_H