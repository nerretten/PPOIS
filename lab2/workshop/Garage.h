#ifndef GARAGE_H
#define GARAGE_H
#include <vector>
#include "../vehicle/Vehicle.h"
#include "Bay.h"
#include <iostream>

class Bay;
class Garage {
private:
    std::vector<Bay*> bays;
    int maxBays;
    std::string address;
public:
    Garage(int maxB, const std::string &addr);
    bool parkVehicle(Bay* b, Vehicle* v);
    void open();
    void close();
    const std::vector<Bay*>& getBays() const { return bays; }
};
#endif

