#include "Transmission.h"
#include <iostream>

Transmission::Transmission(std::string type)
        : type(type), gear(0), isEngaged(false) {}

void Transmission::shiftUp() {
    if (gear < 6) gear++;
    std::cout << "Shifted to gear " << gear << "." << std::endl;
}

void Transmission::shiftDown() {
    if (gear > 0) gear--;
    std::cout << "Shifted to gear " << gear << "." << std::endl;
}

int Transmission::getGear() const {
    return gear;
}

std::string Transmission::getType() const {
    return type;
}