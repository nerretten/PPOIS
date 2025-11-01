#include "Battery.h"

Battery::Battery(std::string id, int volt, int cap)
        : id(id), voltage(volt), capacityAh(cap), isCharged(false) {}

void Battery::charge() {
    isCharged = true;
}

void Battery::discharge() {
    isCharged = false;
}

bool Battery::getIsCharged() const {
    return isCharged;
}

int Battery::getVoltage() const {
    return voltage;
}

int Battery::getCapacityAh() const {
    return capacityAh;
}