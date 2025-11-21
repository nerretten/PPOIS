#include "Battery.h"

Battery::Battery(double cap, double level, int age): capacityAh(cap), chargeLevel(level), ageMonths(age) {}
bool Battery::provideStartCurrent(double requiredA) {
    double avail = capacityAh * chargeLevel * 2.0;
    return avail >= requiredA;
}
void Battery::charge(double hours, double amp){
    double add = (amp * hours) / capacityAh;
    chargeLevel = std::min(1.0, chargeLevel + add);
}
double Battery::health() const {
    double degrade = 0.001 * ageMonths;
    return std::max(0.0, chargeLevel - degrade);
}

