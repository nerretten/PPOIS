#include "RepairOrder.h"


RepairOrder::RepairOrder(int id_): id(id_), paid(false) {}

const std::vector<WorkItem*>& RepairOrder::getItems() const{
    return items;
}

void RepairOrder::addWorkItem(WorkItem* w){
    items.push_back(w);
}

double RepairOrder::totalCost() const {
    double tot = 0.0;
    for (auto w: items)
        tot += w->estimateCost();
    return tot;
}
void RepairOrder::markPaid(){
    paid = true;
}

