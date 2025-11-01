#include "Suspension.h"
#include <iostream>

Suspension::Suspension(std::string type, double wear)
        : type(type), shockAbsorberWear(wear) {}

void Suspension::inspect() {
    if (shockAbsorberWear > 50.0) {
        std::cout << "Suspension needs replacement!" << std::endl;
    }
}

void Suspension::replaceShockAbsorbers() {
    shockAbsorberWear = 0.0;
    std::cout << "Shock absorbers replaced." << std::endl;
}

double Suspension::getShockAbsorberWear() const {
    return shockAbsorberWear;
}

std::string Suspension::getType() const {
    return type;
}