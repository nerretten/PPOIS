#include "Warehouse.h"
#include "../exceptions.h"
#include <iostream>
#include <algorithm>

Warehouse::Warehouse(std::string loc) : location(loc) {}

void Warehouse::addPart(Part* part) {
    parts.push_back(part);
}

void Warehouse::addTool(Tool* tool) {
    tools.push_back(tool);
}

Part* Warehouse::findPartById(std::string id){
    for (Part* p : parts) {
        if (p->getName() == id) {
            return p;
        }
    }
    throw AccountNotFoundException("Part not found: " + id);
}

Tool* Warehouse::findToolById(std::string id){
    for (Tool* t : tools) {
        if (t->getName() == id) {
            return t;
        }
    }
    throw AccountNotFoundException("Tool not found: " + id);
}

void Warehouse::listInventory() const {
    std::cout << "=== Warehouse Inventory ===" << std::endl;
    std::cout << "Parts:" << std::endl;
    for (const Part* p : parts) {
        std::cout << "  " << p->getName() << " (Qty: " << p->getQuantity() << ")" << std::endl;
    }
    std::cout << "Tools:" << std::endl;
    for (const Tool* t : tools) {
        std::cout << "  " << t->getName() << " (Available: " << (t->getIsAvailable() ? "Yes" : "No") << ")" << std::endl;
    }
}

std::vector<Part*> Warehouse::getParts() const{
    return parts;
}