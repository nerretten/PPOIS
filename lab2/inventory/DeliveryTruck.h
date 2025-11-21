#ifndef DELIVERY_TRUCK_H
#define DELIVERY_TRUCK_H
#include <string>
#include "Shipment.h"

class Shipment;
class DeliveryTruck {
private:
    std::string plate;
    double capacityM3;
    Shipment* currentShipment;
public:
    DeliveryTruck(const std::string &p, double cap, Shipment* s);
    void load(Shipment* s);
    void deliver();
    double estimateETA(double km);
};
#endif

