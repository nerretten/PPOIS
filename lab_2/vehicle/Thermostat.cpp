#include "Thermostat.h"

Thermostat::Thermostat(double openT, double curT, int cycles): openTemp(openT), currentTemp(curT), cyclesOperated(cycles) {}
bool Thermostat::shouldOpen(){ return currentTemp >= openTemp; }
void Thermostat::operate(double engineTemp){ currentTemp = engineTemp; cyclesOperated++; }
double Thermostat::estimateFailureProb() const { return std::min(1.0, cyclesOperated / 10000.0); }

