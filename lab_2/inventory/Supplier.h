#ifndef SUPPLIER_H
#define SUPPLIER_H
#include <string>
#include "PurchaseOrder.h"
#include "Shipment.h"
#include "exceptions/InvalidAppointmentException.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

class PurchaseOrder;
class Supplier {
private:
    std::string name;
    std::string contact;
    int leadTimeDays;
public:
    Supplier(const std::string &n, const std::string &c, int lead);
    PurchaseOrder* makeOrder(const std::string &sku, int qty);
    bool checkLeadTime(int days) const;
    void notifyShipment();
};
#endif

