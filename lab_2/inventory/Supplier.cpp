#include "Supplier.h"

Supplier::Supplier(const std::string &n, const std::string &c, int lead)
        : name(n), contact(c), leadTimeDays(lead) {
    if (lead < 0) {
        throw std::invalid_argument("Lead time cannot be negative");
    }
    if (n.empty() || c.empty()) {
        throw std::invalid_argument("Name and contact must not be empty");
    }
}

PurchaseOrder* Supplier::makeOrder(const std::string &sku, int qty) {
    if (sku.empty()) {
        throw std::invalid_argument("SKU cannot be empty");
    }
    if (qty <= 0) {
        throw std::invalid_argument("Order quantity must be positive");
    }
    PurchaseOrder* order = new PurchaseOrder(sku, qty);
    std::cout << "[Supplier] Order created: " << qty << " units of " << sku
              << " from " << name << std::endl;
    return order;
}

bool Supplier::checkLeadTime(int days) const {
    return days >= leadTimeDays;
}

void Supplier::notifyShipment() {
    std::ostringstream msg;
    msg << "Shipment notification sent to " << contact
        << " regarding upcoming delivery (lead time: " << leadTimeDays << " days).";
    std::cout << "[Supplier] " << msg.str() << std::endl;
}