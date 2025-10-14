#include "ServiceOrder.h"

ServiceOrder::ServiceOrder(int orderId, const Car& car) : orderId(orderId), car(car){}
void ServiceOrder::addPart(const Part& part){
    parts.push_back(part);
}
void ServiceOrder::assign_mechanic(const Mechanic& mechanic){
    assigned_mechanics.push_back(mechanic);
}
double ServiceOrder::calculate_total_cost() const{
    double sum = 0.0;
    for(const auto& part: parts)
        sum+=part.get_price();
    return sum;
}