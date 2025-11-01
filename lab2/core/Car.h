#ifndef CAR_H
#define CAR_H

#include "Engine.h"
#include "Transmission.h"
#include "Battery.h"
#include "BrakeSystem.h"
#include "Suspension.h"
#include "Tire.h"
#include "SteeringWheel.h"
#include "Headlight.h"
#include "Radiator.h"
#include "ExhaustSystem.h"
#include <string>

class Car {
private:
    std::string vin;
    std::string model;
    int year;
    Engine engine;
    Transmission transmission;
    Battery battery;
    BrakeSystem brakes;
    Suspension suspension;
    Tire tires[4];
    SteeringWheel steering;
    Headlight headlights[2];
    Radiator radiator;
    ExhaustSystem exhaust;

public:
    Car(std::string vin, std::string model, int year);
    void startEngine();
    void stopEngine();
    void drive();
    void brake();
    void turnLeft();
    void turnRight();
    std::string getVin() const;
    std::string getModel() const;
};

#endif // CAR_H