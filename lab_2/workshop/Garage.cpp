#include "Garage.h"


Garage::Garage(int maxB, const std::string &addr)
        : maxBays(maxB), address(addr) {
    for (int i = 0; i < maxBays; ++i) {
        bays.push_back(new Bay("Bay-" + std::to_string(i + 1)));
    }
}

bool Garage::parkVehicle(Bay* b, Vehicle* v) {
    if (!b || !v)
        return false;

    bool bayExists = false;
    for (Bay* bay : bays) {
        if (bay == b) {
            bayExists = true;
            break;
        }
    }
    if (!bayExists) return false;

    b->assignVehicle(v);
    return true;
}

void Garage::open() {
    std::cout << "[Garage] Opened at " << address << " with " << maxBays << " bays." << std::endl;
}

void Garage::close() {
    std::cout << "[Garage] Closed at " << address << ". Releasing all vehicles." << std::endl;
    for (Bay* b : bays) {
        if (b && b->isOccupied()) {
            b->releaseVehicle();
        }
    }
}