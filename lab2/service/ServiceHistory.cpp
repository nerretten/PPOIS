#include "ServiceHistory.h"


ServiceHistory::ServiceHistory(): totalServices(0), totalCost(0.0) {}
void ServiceHistory::addOrder(RepairOrder* r){
    orders.push_back(r);
    totalServices++;
    totalCost += r->totalCost();
}
double ServiceHistory::averageCost() const {
    return totalServices==0 ? 0.0 : totalCost / totalServices;
}
int ServiceHistory::count(){
    return totalServices;
}
