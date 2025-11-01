#ifndef SERVICEORDER_H
#define SERVICEORDER_H

#include "Service.h"
#include "../employees/Mechanic.h"
#include "../utilities/Date.h"
#include <string>
#include <vector>

class ServiceOrder {
private:
    std::string orderId;
    Date orderDate;
    std::vector<Service*> services;
    Mechanic* assignedMechanic;
    std::string status;

public:
    ServiceOrder(std::string id, Date date);
    void addService(Service* service);
    void assignMechanic(Mechanic* mech);
    void complete();
    void printOrder() const;
    std::string getOrderId() const;
    std::vector<Service*> getServices() const;
    Date getDate() const;
};

#endif // SERVICEORDER_H