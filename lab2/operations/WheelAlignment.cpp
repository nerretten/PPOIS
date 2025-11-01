#include "WheelAlignment.h"
#include <iostream>

WheelAlignment::WheelAlignment(std::string desc, Car* c, double toe, double cam, double cast)
        : Service(desc), car(c), toeIn(toe), camber(cam), caster(cast), isAligned(false) {}

void WheelAlignment::perform() {
    std::cout << "Performing wheel alignment on car " << car->getVin() << std::endl;
    isAligned = true;
    std::cout << "Toe-in: " << toeIn << ", Camber: " << camber << ", Caster: " << caster << std::endl;
}

void WheelAlignment::schedule() {
    std::cout << "Wheel alignment scheduled for car " << car->getVin() << std::endl;
}

bool WheelAlignment::getIsAligned() const {
    return isAligned;
}