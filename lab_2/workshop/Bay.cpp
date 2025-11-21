#include "Bay.h"
#include <iostream>

Bay::Bay(const std::string &n): name(n), currentVehicle(nullptr), occupied(false) {}
void Bay::assignVehicle(Vehicle* v){
    currentVehicle = v;
    occupied = (v!=nullptr);
}
void Bay::releaseVehicle(){
    currentVehicle = nullptr;
    occupied = false;
}
bool Bay::isOccupied() const {
    return occupied;
}

