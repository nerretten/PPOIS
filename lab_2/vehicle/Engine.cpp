#include "Engine.h"


Engine::Engine(int cyl, double disp, Battery* b): cylinders(cyl), displacement(disp), battery(b) {}
bool Engine::start() {
    double need = 200.0;
    if (!battery) throw std::runtime_error("No battery");
    bool ok = battery->provideStartCurrent(need);
    if (!ok) return false;
    return true;
}
double Engine::computeFuelConsumption(double hours, double rpm) {
    double base = displacement * 0.1;
    double rpmFactor = (rpm / 1000.0) * 0.05;
    return hours * (base + rpmFactor);
}
double Engine::checkCompression() {
    return std::max(0.0, 1.0 - (displacement - 1.0) * 0.05);
}
void Engine::replaceBattery(Battery* b) { battery = b; }

