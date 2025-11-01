#ifndef PAYMENTRECEIPT_H
#define PAYMENTRECEIPT_H

#include "Invoice.h"
#include "../utilities/Date.h"
#include <string>

class PaymentReceipt {
private:
    std::string receiptId;
    Date paymentDate;
    double amountPaid;
    Invoice* relatedInvoice;
    std::string paymentMethod;

public:
    PaymentReceipt(std::string id, Date date, double amount, Invoice* inv, std::string method);
    void printReceipt() const;
    std::string getReceiptId() const;
    double getAmountPaid() const;
};

#endif // PAYMENTRECEIPT_H