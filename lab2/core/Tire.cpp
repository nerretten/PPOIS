#include "Tire.h"
#include <iostream>

Tire::Tire() = default;

Tire::Tire(std::string id, std::string type, double tread, int rim)
        : id(id), type(type), treadDepth(tread), rimSize(rim) {}

void Tire::inspect() {
    if (treadDepth < 1.6) {
        std::cout << "Tire tread too low!" << std::endl;
    }
}

void Tire::rotate() {
    treadDepth -= 0.1;
    std::cout << "Tire rotated." << std::endl;
}

double Tire::getTreadDepth() const {
    return treadDepth;
}

std::string Tire::getType() const {
    return type;
}