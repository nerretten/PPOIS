#include "Inventory.h"

Inventory::Inventory(int loc, double cap): locationId(loc), capacity(cap) {}

void Inventory::addStock(StockItem* s){
    items.push_back(s);
}

void Inventory::reserve(const std::string &sku, int qty) {
    for (auto item : items) {
        if (item && item->checkTemperature() && item->getSKU() == sku) {
            if (item->getQuantity() >= qty) {
                item->consume(qty);
                return;
            } else {
                throw InsufficientStockException();
            }
        }
    }
    throw PartNotFoundException();
}

int Inventory::available(const std::string &sku) const {
    for (auto item : items) {
        if (item && item->getSKU() == sku && item->checkTemperature()) {
            return item->getQuantity();
        }
    }
    return 0;
}

