#include "Invoice.h"
#include <iostream>

Invoice::Invoice(std::string id, Date issue, Date due, double amount, ServiceOrder* order)
        : invoiceId(id), issueDate(issue), dueDate(due), totalAmount(amount), paid(false), relatedOrder(order) {}

void Invoice::markAsPaid() {
    paid = true;
    std::cout << "Invoice " << invoiceId << " marked as paid." << std::endl;
}

bool Invoice::isOverdue() const {
    Date today(2025, 10, 29);
    return dueDate < today && !paid;
}

double Invoice::getRemainingBalance() const {
    return paid ? 0.0 : totalAmount;
}

std::string Invoice::getInvoiceId() const {
    return invoiceId;
}

double Invoice::getTotalAmount() const {
    return totalAmount;
}