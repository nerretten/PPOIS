#ifndef INVOICE_H
#define INVOICE_H

#include "../utilities/Date.h"
#include "../operations/ServiceOrder.h"
#include <string>

class Invoice {
private:
    std::string invoiceId;
    Date issueDate;
    Date dueDate;
    double totalAmount;
    bool paid;
    ServiceOrder* relatedOrder;

public:
    Invoice(std::string id, Date issue, Date due, double amount, ServiceOrder* order);
    void markAsPaid();
    bool isOverdue() const;
    double getRemainingBalance() const;
    std::string getInvoiceId() const;
    double getTotalAmount() const;
};

#endif // INVOICE_H