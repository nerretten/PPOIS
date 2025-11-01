#include "PartsCatalog.h"
#include "../exceptions.h"
#include <iostream>

void PartsCatalog::addPart(Part* part) {
    parts.push_back(part);
}

Part* PartsCatalog::findPartByName(std::string name){
    for (Part* p : parts) {
        if (p->getName() == name) {
            return p;
        }
    }
    throw AccountNotFoundException("Part not found: " + name);
}

std::vector<Part*> PartsCatalog::getAllParts() const {
    return parts;
}

void PartsCatalog::printCatalog() const {
    std::cout << "=== Parts Catalog ===" << std::endl;
    for (const Part* p : parts) {
        std::cout << "  " << p->getName() << " (Price: " << p->getPrice() << ", Qty: " << p->getQuantity() << ")" << std::endl;
    }
}