#include "FuelSystem.h"

FuelSystem::FuelSystem(double cap, double cur, int inj): tankCapacity(cap), currentVolume(cur), injectorCount(inj) {}
double FuelSystem::inject(double seconds, double ratePerInjector) {
    double used = seconds * ratePerInjector * injectorCount;
    if (used > currentVolume) used = currentVolume;
    currentVolume -= used;
    return used;
}
double FuelSystem::estimateRange(double consumptionLPer100) {
    if (consumptionLPer100<=0) return 0;
    return (currentVolume / consumptionLPer100) * 100.0;
}
void FuelSystem::siphon(double liters) { currentVolume = std::max(0.0, currentVolume - liters); }

