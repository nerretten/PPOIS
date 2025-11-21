#include "Lift.h"


Lift::Lift(double cap, double load, const std::string &s): capacityKg(cap), currentLoad(load), state(s) {}
void Lift::liftVehicle(Vehicle* v) {
    (void)v;
    if (currentLoad > capacityKg) throw LiftOverloadException();
    state = "up";
}
void Lift::lower(){
    state = "down";
}
bool Lift::safetyCheck(){
    return currentLoad <= capacityKg;
}
const std::string&  Lift::getState() const {
    return state;
}
