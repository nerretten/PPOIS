#include "Radiator.h"
#include <iostream>

Radiator::Radiator(std::string id, double level)
        : id(id), coolantLevel(level), isLeaking(false) {}

void Radiator::checkCoolant() {
    if (coolantLevel < 30.0) {
        std::cout << "Low coolant level!" << std::endl;
        isLeaking = true;
    }
}

void Radiator::refillCoolant(double amount) {
    coolantLevel += amount;
    if (coolantLevel > 100.0) coolantLevel = 100.0;
    isLeaking = false;
    std::cout << "Coolant refilled to " << coolantLevel << "%." << std::endl;
}

double Radiator::getCoolantLevel() const {
    return coolantLevel;
}

bool Radiator::getIsLeaking() const {
    return isLeaking;
}