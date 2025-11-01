#ifndef PARTSCATALOG_H
#define PARTSCATALOG_H

#include "../inventory/Part.h"
#include <vector>
#include <string>

class PartsCatalog {
private:
    std::vector<Part*> parts;

public:
    void addPart(Part* part);
    Part* findPartByName(std::string name);
    std::vector<Part*> getAllParts() const;
    void printCatalog() const;
};

#endif // PARTSCATALOG_H