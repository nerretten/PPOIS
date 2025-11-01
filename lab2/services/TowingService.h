#ifndef TOWINGSERVICE_H
#define TOWINGSERVICE_H

#include "../core/Car.h"
#include <string>

class TowingService {
private:
    Car* towedCar;
    std::string requesterName;
    std::string destination;
    double cost;
    bool isCompleted;

public:
    TowingService(Car* car, std::string request, std::string dest, double price);
    void dispatch();
    void complete();
    double getCost() const;
    std::string getDestination() const;
};

#endif // TOWINGSERVICE_H