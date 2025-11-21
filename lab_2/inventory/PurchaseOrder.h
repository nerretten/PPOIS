#ifndef PURCHASE_ORDER_H
#define PURCHASE_ORDER_H
#include <string>
#include "Shipment.h"
#include "exceptions/InsufficientStockException.h"
#include <stdexcept>
#include <iostream>

class Shipment;
class PurchaseOrder {
private:
    std::string sku;
    int quantity;
    bool received;
public:
    PurchaseOrder(const std::string &sku_, int q);
    void markReceived(Shipment* s);
    int getQuantity() const;
    double expectedCost(double unitPrice) const;
    bool isReceived() const;
    const std::string& getSKU() const;
};
#endif

