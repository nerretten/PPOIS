#ifndef COOLING_SYSTEM_H
#define COOLING_SYSTEM_H

#include "Radiator.h"
#include "Thermostat.h"

class CoolingSystem {
private:
    Radiator* radiator;
    Thermostat* thermostat;
    double pumpFlow;
public:
    CoolingSystem(Radiator* r, Thermostat* t, double flow);
    double regulate(double engineTemp);
    void flushAll();
    bool checkLeaks();
};
#endif

