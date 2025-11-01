#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <vector>
#include "Part.h"
#include "Tool.h"

class Warehouse {
private:
    std::string location;
    std::vector<class Part*> parts;
    std::vector<class Tool*> tools;

public:
    Warehouse(std::string loc);
    void addPart(Part* part);
    void addTool(Tool* tool);
    Part* findPartById(std::string id);
    Tool* findToolById(std::string id);
    void listInventory() const;
    std::vector<Part*> getParts() const;
};

#endif // WAREHOUSE_H