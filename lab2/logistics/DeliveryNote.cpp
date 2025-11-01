#include "DeliveryNote.h"
#include <iostream>

DeliveryNote::DeliveryNote(Shipment* ship, Date date)
        : shipment(ship), deliveryDate(date), receiverSignature("") {}

void DeliveryNote::sign(std::string signature) {
    receiverSignature = signature;
    std::cout << "Delivery note signed by: " << signature << std::endl;
}

bool DeliveryNote::isSigned() const {
    return !receiverSignature.empty();
}

std::string DeliveryNote::getDeliveryDetails() const {
    return "Shipment: " + shipment->getTrackingNumber() + ", Delivered on: " + deliveryDate.toString();
}