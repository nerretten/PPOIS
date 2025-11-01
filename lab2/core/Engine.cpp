#include "Engine.h"
#include <iostream>

Engine::Engine(std::string t, int hp)
        : type(t), horsepower(hp), isRunning(false) {}

void Engine::start() {
    isRunning = true;
    std::cout << "Engine started." << std::endl;
}

void Engine::stop() {
    isRunning = false;
    std::cout << "Engine stopped." << std::endl;
}

bool Engine::getIsRunning() const {
    return isRunning;
}

int Engine::getHorsepower() const {
    return horsepower;
}