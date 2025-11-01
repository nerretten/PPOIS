#include "ToolInventory.h"
#include "../exceptions.h"
#include <iostream>

void ToolInventory::addTool(Tool* tool) {
    tools.push_back(tool);
}

Tool* ToolInventory::findToolByName(std::string name) {
    for (Tool* t : tools) {
        if (t->getName() == name) {
            return t;
        }
    }
    throw AccountNotFoundException("Tool not found: " + name);
}

std::vector<Tool*> ToolInventory::getAllTools() const {
    return tools;
}

void ToolInventory::printInventory() const {
    std::cout << "=== Tool Inventory ===" << std::endl;
    for (const Tool* t : tools) {
        std::cout << "  " << t->getName() << " (Available: " << (t->getIsAvailable() ? "Yes" : "No") << ")" << std::endl;
    }
}