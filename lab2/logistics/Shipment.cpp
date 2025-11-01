#include "Shipment.h"
#include "../exceptions.h"
#include <iostream>

Shipment::Shipment(Supplier* sup, Date date, std::string track)
        : supplier(sup), shipmentDate(date), trackingNumber(track), delivered(false) {}

void Shipment::addPart(Part* part) {
    parts.push_back(part);
}

void Shipment::deliver(){
    for (Part* p : parts) {
        if (p->getQuantity() == 0) {
            throw PartNotInStockException("Part " + p->getName() + " is out of stock.");
        }
    }
    delivered = true;
    std::cout << "Shipment " << trackingNumber << " delivered." << std::endl;
}

void Shipment::markAsDelivered() {
    delivered = true;
    std::cout << "Shipment " << trackingNumber << " marked as delivered." << std::endl;
}

std::string Shipment::getTrackingNumber() const {
    return trackingNumber;
}

bool Shipment::getIsDelivered() const {
    return delivered;
}