#ifndef LAB2_INVOICE_H
#define LAB2_INVOICE_H
#include "Client.h"
#include "../operations/ServiceOrder.h"
#include "../utilities/Date.h"

class Invoice{
private:
    Client client;
    ServiceOrder order;
    Date date;
public:
    Invoice(const Client& client, const ServiceOrder& order, const Date& date);
    double generate_total();
};


#endif //LAB2_INVOICE_H
