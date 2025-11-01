#ifndef SERVICESCHEDULE_H
#define SERVICESCHEDULE_H

#include "../utilities/Date.h"
#include "../operations/ServiceOrder.h"
#include <vector>

class ServiceSchedule {
private:
    std::vector<ServiceOrder*> scheduledOrders;
    Date startDate;
    Date endDate;

public:
    ServiceSchedule(Date start, Date end);
    void addOrder(ServiceOrder* order);
    void removeOrder(ServiceOrder* order);
    void printSchedule() const;
    std::vector<ServiceOrder*> getOrdersForDate(Date date) const;
};

#endif // SERVICESCHEDULE_H