#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <vector>
#include "Engine.h"
#include "Transmission.h"
#include "Wheel.h"
#include "../service/ServiceHistory.h"
#include <algorithm>
class Engine;
class Transmission;
class Wheel;
class ServiceHistory;
class Vehicle {
private:
    std::string vin;
    Engine* engine;
    Transmission* transmission;
public:
    Vehicle(const std::string &vin_, Engine* e, Transmission* t);
    double runEngineFor(double hours);
    void changeEngine(Engine* newEngine);
    std::string getVIN() const;
    void attachWheel(Wheel* w);
    void detachWheel(Wheel* w);
    void recordService(ServiceHistory* h);
    int wheelCount() const;
    ~Vehicle();
private:
    std::vector<Wheel*> wheels;
    ServiceHistory* history;
};
#endif

