#include "Warehouse.h"

void Warehouse::add_part(const Part& part){
    inventory.push_back(part);
}
int Warehouse::get_part_count() const{
    return inventory.size();
}
void Warehouse::remove_part_by_name(const std::string& s){
    if(inventory.empty()){
        throw WarehouseEmptyException();
    }
    for(auto it = inventory.begin(); it  != inventory.end(); it++){
        if(it->get_name() == s) {
            inventory.erase(it);
            return;
        }
    }
    throw PartNotFound();
}