#ifndef SHIPMENT_H
#define SHIPMENT_H

#include "../Inventory/Supplier.h"
#include "../Inventory/Part.h"
#include "../utilities/Date.h"
#include <vector>
#include <string>

class Shipment {
private:
    Supplier* supplier;
    std::vector<Part*> parts;
    Date shipmentDate;
    std::string trackingNumber;
    bool delivered;

public:
    Shipment(Supplier* sup, Date date, std::string track);
    void addPart(Part* part);
    void deliver();
    void markAsDelivered();
    std::string getTrackingNumber() const;
    bool getIsDelivered() const;
};

#endif // SHIPMENT_H