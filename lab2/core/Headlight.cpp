#include "Headlight.h"
#include <iostream>

Headlight::Headlight() = default;
Headlight::Headlight(std::string id, std::string type)
        : id(id), type(type), isOn(false) {}

void Headlight::turnOn() {
    isOn = true;
    std::cout << "Headlight turned on." << std::endl;
}

void Headlight::turnOff() {
    isOn = false;
    std::cout << "Headlight turned off." << std::endl;
}

bool Headlight::getIsOn() const {
    return isOn;
}

std::string Headlight::getType() const {
    return type;
}