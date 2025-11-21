#ifndef REPAIR_ORDER_H
#define REPAIR_ORDER_H
#include <vector>
#include <string>
#include "WorkItem.h"
class WorkItem;
class RepairOrder {
private:
    int id;
    std::vector<WorkItem*> items;
    bool paid;
public:
    RepairOrder(int id_);
    const std::vector<WorkItem*>& getItems() const;
    void addWorkItem(WorkItem* w);
    double totalCost() const;
    void markPaid();
};
#endif

