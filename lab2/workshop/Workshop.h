#ifndef WORKSHOP_H
#define WORKSHOP_H

#include <string>
#include <vector>
#include "../employees/Mechanic.h"
#include "../operations/ServiceOrder.h"
#include "../logistics/InventoryManager.h"
#include "../security/AuditLog.h"

class Workshop {
private:
    std::string name;
    std::string address;
    std::vector<Mechanic*> mechanics;
    std::vector<ServiceOrder*> activeOrders;
    InventoryManager* inventoryManager;
    AuditLog* auditLog;

public:
    Workshop(std::string name, std::string addr, InventoryManager* inv, AuditLog* log);
    void addMechanic(Mechanic* mech);
    void createServiceOrder(ServiceOrder* order);
    void assignOrderToMechanic(ServiceOrder* order, Mechanic* mech);
    void completeOrder(ServiceOrder* order);
    void printStatus() const;
    std::string getName() const;
};

#endif // WORKSHOP_H