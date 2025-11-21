#include "Invoice.h"

Invoice::Invoice(int no, RepairOrder* o)
        : invoiceNo(no), order(o), paidAmount(0.0) {
    if (!o) {
        throw std::invalid_argument("RepairOrder cannot be null");
    }
}

double Invoice::calculateTotal() const {
    return order ? order->totalCost() : 0.0;
}

bool Invoice::isPaid() const {
    return paidAmount >= calculateTotal();
}

void Invoice::applyPayment(double amount) {
    if (amount <= 0.0) {
        throw std::invalid_argument("Payment amount must be positive");
    }
    if (isPaid()) {
        throw std::logic_error("Invoice already paid in full");
    }
    paidAmount += amount;
    if (isPaid()) {
        order->markPaid();
    }
}

std::string Invoice::summary() const {
    std::ostringstream ss;
    ss << "Invoice #" << invoiceNo
       << " | Total: $" << std::fixed << std::setprecision(2) << calculateTotal()
       << " | Paid: $" << std::fixed << std::setprecision(2) << paidAmount
       << " | Status: " << (isPaid() ? "PAID" : "PENDING");
    return ss.str();
}