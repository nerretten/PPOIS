#ifndef LAB2_SERVICEORDER_H
#define LAB2_SERVICEORDER_H
#include <vector>
#include "../core/Car.h"
#include "../employees/Mechanic.h"
#include "../inventory/Part.h"


class ServiceOrder{
private:
    int orderId;
    Car car;
    std::vector<Part> parts;
    std::vector<Mechanic> assigned_mechanics;
public:
    ServiceOrder(int orderId, const Car& car);
    void addPart(const Part& part);
    void assign_mechanic(const Mechanic& mechanic);
    double calculate_total_cost() const;
};


#endif
