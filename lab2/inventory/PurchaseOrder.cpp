#include "PurchaseOrder.h"
#include "Shipment.h"


PurchaseOrder::PurchaseOrder(const std::string &sku_, int q)
        : sku(sku_), quantity(q), received(false) {
    if (quantity <= 0) {
        throw std::invalid_argument("Purchase order quantity must be positive");
    }
}

void PurchaseOrder::markReceived(Shipment* s) {
    if (!s) {
        throw std::invalid_argument("Shipment cannot be null");
    }
    if (s->getItemsount() < quantity) {
        throw InsufficientStockException();
    }
    received = true;
    std::cout << "[PurchaseOrder] Order for " << quantity << " units of " << sku
              << " marked as received." << std::endl;
}

double PurchaseOrder::expectedCost(double unitPrice) const {
    if (unitPrice < 0.0) {
        throw std::invalid_argument("Unit price cannot be negative");
    }
    return unitPrice * static_cast<double>(quantity);
}

int PurchaseOrder::getQuantity() const {
    return quantity;
}

bool PurchaseOrder::isReceived() const {
    return received;
}

const std::string& PurchaseOrder::getSKU() const {
    return sku;
}