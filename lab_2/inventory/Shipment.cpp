#include "Shipment.h"

Shipment::Shipment(const std::string &t, int items, double w): tracking(t), itemsCount(items), weightKg(w) {}
void Shipment::track(){}
void Shipment::receive(){
    itemsCount = 0;
}
double Shipment::averageItemWeight() const {
    return itemsCount == 0 ? 0: weightKg / itemsCount;
}
int Shipment::getItemsount() const {
    return itemsCount;
}
