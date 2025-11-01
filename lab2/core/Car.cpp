#include "Car.h"
#include <iostream>

Car::Car(std::string vin, std::string model, int year)
        : vin(vin), model(model), year(year),
          engine("V8", 350),
          transmission("Automatic"),
          battery("BATT001", 12, 60),
          brakes("disc", 10.0),
          suspension("Independent"),
          steering("Electric"),
          radiator("RADIATOR001", 10.0),
          exhaust("EXHAUST001", "Stainless Steel")
{
    for (int i = 0; i < 4; ++i) {
        tires[i] = Tire("TIRE" + std::to_string(i+1), "Summer", 225, 45);
    }
    headlights[0] = Headlight("HEADLIGHT_LEFT", "LED");
    headlights[1] = Headlight("HEADLIGHT_RIGHT", "LED");
}

void Car::startEngine() {
    engine.start();
    std::cout << "Car engine started." << std::endl;
}

void Car::stopEngine() {
    engine.stop();
    std::cout << "Car engine stopped." << std::endl;
}

void Car::drive() {
    std::cout << "Car is driving." << std::endl;
}

void Car::brake() {
    brakes.inspect();
    if (!brakes.getIsFunctional()) {
        std::cout << "Brakes need replacement!" << std::endl;
    } else {
        std::cout << "Braking..." << std::endl;
    }
}

void Car::turnLeft() {
    steering.turnLeft();
    std::cout << "Turning left." << std::endl;
}

void Car::turnRight() {
    steering.turnRight();
    std::cout << "Turning right." << std::endl;
}

std::string Car::getVin() const {
    return vin;
}

std::string Car::getModel() const {
    return model;
}