#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "StockItem.h"
#include "../exceptions/PartNotFoundException.h"
#include "../exceptions/InsufficientStockException.h"
#include <stdexcept>

class StockItem;
class Inventory {
private:
    std::vector<StockItem*> items;
    int locationId;
    double capacity;
public:
    Inventory(int loc, double cap);
    void addStock(StockItem* s);
    void reserve(const std::string &sku, int qty);
    int available(const std::string &sku) const;
};
#endif

