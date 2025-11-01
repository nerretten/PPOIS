#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "BankAccount.h"
#include <string>

class CreditCard {
private:
    std::string cardNumber;
    std::string holderName;
    BankAccount* linkedAccount;
    double creditLimit;
    double currentDebt;

public:
    CreditCard(std::string num, std::string holder, BankAccount* acc, double limit);
    bool validatePin(int pin);
    void makePayment(double amount);
    double getAvailableCredit() const;
    std::string getCardNumber() const;
};

#endif // CREDITCARD_H