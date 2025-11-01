#ifndef TOOLINVENTORY_H
#define TOOLINVENTORY_H

#include "../Inventory/Tool.h"
#include <vector>
#include <string>

class ToolInventory {
private:
    std::vector<Tool*> tools;

public:
    void addTool(Tool* tool);
    Tool* findToolByName(std::string name);
    std::vector<Tool*> getAllTools() const;
    void printInventory() const;
};

#endif // TOOLINVENTORY_H