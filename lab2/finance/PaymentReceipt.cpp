#include "PaymentReceipt.h"
#include <iostream>

PaymentReceipt::PaymentReceipt(std::string id, Date date, double amount, Invoice* inv, std::string method)
        : receiptId(id), paymentDate(date), amountPaid(amount), relatedInvoice(inv), paymentMethod(method) {}

void PaymentReceipt::printReceipt() const {
    std::cout << "=== Payment Receipt ===" << std::endl;
    std::cout << "ID: " << receiptId << std::endl;
    std::cout << "Date: " << paymentDate.toString() << std::endl;
    std::cout << "Amount Paid: " << amountPaid << std::endl;
    std::cout << "Invoice ID: " << relatedInvoice->getInvoiceId() << std::endl;
    std::cout << "Payment Method: " << paymentMethod << std::endl;
}

std::string PaymentReceipt::getReceiptId() const {
    return receiptId;
}

double PaymentReceipt::getAmountPaid() const {
    return amountPaid;
}