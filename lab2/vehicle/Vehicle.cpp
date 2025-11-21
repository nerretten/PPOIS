#include "Vehicle.h"


Vehicle::Vehicle(const std::string &vin_, Engine* e, Transmission* t)
: vin(vin_), engine(e), transmission(t), history(nullptr) {}

double Vehicle::runEngineFor(double hours) {
    if (!engine) return 0.0;
    double fuel = engine->computeFuelConsumption(hours, 2000);
    if (history) {
        RepairOrder* order = new RepairOrder(-1);
        history->addOrder(order);
    }

    return fuel;
}
void Vehicle::changeEngine(Engine* newEngine) {
    engine = newEngine;
}
std::string Vehicle::getVIN() const {
    return vin;
}
void Vehicle::attachWheel(Wheel* w) {
    wheels.push_back(w);
}
void Vehicle::detachWheel(Wheel* w) {
    wheels.erase(std::remove(wheels.begin(), wheels.end(), w), wheels.end());
}
void Vehicle::recordService(ServiceHistory* h) {
    history = h;
}
int Vehicle::wheelCount() const {
    return (int)wheels.size();
}
Vehicle::~Vehicle(){}

