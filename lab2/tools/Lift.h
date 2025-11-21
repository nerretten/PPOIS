#ifndef LIFT_H
#define LIFT_H
#include <string>
#include "../vehicle/Vehicle.h"
#include "../exceptions/LiftOverloadException.h"
#include <stdexcept>
class Vehicle;
class Lift {
private:
    double capacityKg;
    double currentLoad;
    std::string state;
public:
    Lift(double cap, double load, const std::string &s);
    const std::string& getState() const;
    void liftVehicle(Vehicle* v);
    void lower();
    bool safetyCheck();
};
#endif

