#ifndef SERVICE_HISTORY_H
#define SERVICE_HISTORY_H
#include <vector>
#include "RepairOrder.h"

class RepairOrder;
class ServiceHistory {
private:
    std::vector<RepairOrder*> orders;
    int totalServices;
    double totalCost;
public:
    ServiceHistory();
    void addOrder(RepairOrder* r);
    double averageCost() const;
    int count();
};
#endif


