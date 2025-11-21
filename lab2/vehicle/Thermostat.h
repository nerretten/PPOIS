#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <algorithm>

class Thermostat {
private:
    double openTemp;
    double currentTemp;
    int cyclesOperated;
public:
    Thermostat(double openT, double curT, int cycles);
    bool shouldOpen();
    void operate(double engineTemp);
    double estimateFailureProb() const;
};
#endif

