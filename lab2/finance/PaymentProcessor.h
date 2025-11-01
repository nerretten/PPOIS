#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

#include "CreditCard.h"
#include "BankAccount.h"
#include <string>

class PaymentProcessor {
public:
    static bool processPayment(CreditCard& card, double amount, int pin);
    static void refund(BankAccount& account, double amount);
};

#endif // PAYMENTPROCESSOR_H