#include "ExhaustSystem.h"
#include <iostream>

ExhaustSystem::ExhaustSystem(std::string id, std::string mat, double noise)
        : id(id), material(mat), noiseLevelDb(noise) {}

void ExhaustSystem::inspect() {
    if (noiseLevelDb > 80.0) {
        std::cout << "Exhaust system too noisy!" << std::endl;
    }
}

void ExhaustSystem::replace() {
    noiseLevelDb = 60.0;
    std::cout << "Exhaust system replaced." << std::endl;
}

double ExhaustSystem::getNoiseLevel() const {
    return noiseLevelDb;
}

std::string ExhaustSystem::getMaterial() const {
    return material;
}