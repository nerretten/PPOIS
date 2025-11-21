#ifndef FUEL_SYSTEM_H
#define FUEL_SYSTEM_H

#include <algorithm>

class FuelSystem {
private:
    double tankCapacity;
    double currentVolume;
    int injectorCount;
public:
    FuelSystem(double cap, double cur, int inj);
    double inject(double seconds, double ratePerInjector);
    double estimateRange(double consumptionLPer100);
    void siphon(double liters);
};
#endif

