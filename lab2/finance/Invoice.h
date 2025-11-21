#ifndef INVOICE_H
#define INVOICE_H
#include <string>
#include "../service/RepairOrder.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>

class RepairOrder;

class Invoice {
private:
    int invoiceNo;
    RepairOrder* order;
    double paidAmount;
public:
    Invoice(int no, RepairOrder* o);
    double calculateTotal() const;
    void applyPayment(double amount);
    std::string summary() const;
    bool isPaid() const;
};

#endif


