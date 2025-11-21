#ifndef BATTERY_H
#define BATTERY_H
#include <algorithm>
class Battery {
private:
    double capacityAh;
    double chargeLevel;
    int ageMonths;
public:
    Battery(double cap, double level, int age);
    bool provideStartCurrent(double requiredA);
    void charge(double hours, double amp);
    double health() const;
};
#endif

