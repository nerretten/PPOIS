#ifndef LAB2_WAREHOUSE_H
#define LAB2_WAREHOUSE_H
#include <vector>
#include "../exceptions.h"
#include "Part.h"

class Warehouse{
private:
    std::vector <Part> inventory;
public:
    void add_part(const Part& part);
    int get_part_count() const;
    void remove_part_by_name(const std::string& s);
};

#endif
