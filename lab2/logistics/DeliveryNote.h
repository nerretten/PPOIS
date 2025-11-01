#ifndef DELIVERYNOTE_H
#define DELIVERYNOTE_H

#include "Shipment.h"
#include "../utilities/Date.h"
#include <string>

class DeliveryNote {
private:
    Shipment* shipment;
    Date deliveryDate;
    std::string receiverSignature;

public:
    DeliveryNote(Shipment* ship, Date date);
    void sign(std::string signature);
    bool isSigned() const;
    std::string getDeliveryDetails() const;
};

#endif // DELIVERYNOTE_H