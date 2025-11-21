#include "DeliveryTruck.h"


DeliveryTruck::DeliveryTruck(const std::string &p, double cap, Shipment* s): plate(p), capacityM3(cap), currentShipment(s) {}
void DeliveryTruck::load(Shipment* s){
    currentShipment = s;
}
void DeliveryTruck::deliver(){
    if (currentShipment)
        currentShipment->receive();
    currentShipment = nullptr;
}
double DeliveryTruck::estimateETA(double km){
    return km / 60.0;
}

