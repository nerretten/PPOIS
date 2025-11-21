#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "Appointment.h"
#include "../service/RepairOrder.h"
#include "../service/WorkItem.h"
#include "../inventory/Part.h"
#include <iostream>
#include <memory>

class Appointment;
class Customer {
private:
    std::string name;
    std::string phone;
    Appointment* nextAppointment;
public:
    Customer(const std::string &n, const std::string &p, Appointment* a);
    void requestService(const std::string &desc);
    void cancelAppointment();
    std::string contactCard() const;
};
#endif

