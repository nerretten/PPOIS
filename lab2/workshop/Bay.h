#ifndef BAY_H
#define BAY_H
#include "../vehicle/Vehicle.h"
#include <string>
class Vehicle;
class Bay {
private:
    std::string name;
    Vehicle* currentVehicle;
    bool occupied;
public:
    Bay(const std::string &n);
    void assignVehicle(Vehicle* v);
    void releaseVehicle();
    bool isOccupied() const;
};
#endif

