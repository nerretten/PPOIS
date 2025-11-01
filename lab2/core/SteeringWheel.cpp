#include "SteeringWheel.h"
#include <iostream>

SteeringWheel::SteeringWheel(std::string type)
        : type(type), angleDegrees(0) {}

void SteeringWheel::turnLeft() {
    angleDegrees = -30;
    std::cout << "Steering wheel turned left." << std::endl;
}

void SteeringWheel::turnRight() {
    angleDegrees = 30;
    std::cout << "Steering wheel turned right." << std::endl;
}

int SteeringWheel::getAngle() const {
    return angleDegrees;
}

std::string SteeringWheel::getType() const {
    return type;
}