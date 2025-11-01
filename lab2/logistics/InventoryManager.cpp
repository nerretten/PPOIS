#include "InventoryManager.h"
#include "../exceptions.h"
#include <iostream>

InventoryManager::InventoryManager(Warehouse* wh) : warehouse(wh) {}

void InventoryManager::updateStock(Part* part, int quantity){
    if (quantity < 0 && part->getQuantity() < -quantity) {
        throw PartNotInStockException("Cannot reduce stock below zero for part: " + part->getName());
    }
    part->setQuantity(part->getQuantity() + quantity);
    std::cout << "Updated stock for part " << part->getName() << " to " << part->getQuantity() << std::endl;
}

int InventoryManager::getStockLevel(std::string partId) const {
    try {
        Part* p = warehouse->findPartById(partId);
        return p->getQuantity();
    } catch (AccountNotFoundException& e) {
        std::cout << e.what() << std::endl;
        return 0;
    }
}

bool InventoryManager::isAvailable(Part* part, int needed) const {
    return part->getQuantity() >= needed;
}

void InventoryManager::checkQuantityParts() const{
    std::cout << "Checking parts..." << std::endl;
    for (Part* p : warehouse->getParts()) {
        if (p->getQuantity() < 5) {
            std::cout << "Pay attention! There are less than 5: " << p->getName() << std::endl;
        }
    }
}

void InventoryManager::printStockReport() const {
    std::cout << "=== Stock Report ===" << std::endl;
    for (Part* p : warehouse->getParts()) {
        std::cout << "  " << p->getName() << ": " << p->getQuantity() << " in stock" << std::endl;
    }
}