#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "../Inventory/Warehouse.h"
#include "../Inventory/Part.h"
#include "../Inventory/Tool.h"
#include <map>
#include <string>

class InventoryManager {
private:
    Warehouse* warehouse;
    std::map<std::string, int> stockLevels;

public:
    InventoryManager(Warehouse* wh);
    void updateStock(Part* part, int quantity);
    int getStockLevel(std::string partId) const;
    bool isAvailable(Part* part, int needed) const;
    void checkQuantityParts() const;
    void printStockReport() const;
};

#endif // INVENTORYMANAGER_H