#include "BrakeSystem.h"

BrakeSystem::BrakeSystem(std::string t, double wear)
        : type(t), padWearPercentage(wear), isFunctional(true) {}

void BrakeSystem::inspect() {
    if (padWearPercentage > 70.0) {
        isFunctional = false;
    }
}

void BrakeSystem::replacePads() {
    padWearPercentage = 0.0;
    isFunctional = true;
}

double BrakeSystem::getPadWear() const {
    return padWearPercentage;
}

bool BrakeSystem::getIsFunctional() const {
    return isFunctional;
}