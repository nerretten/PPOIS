#include "CreditCard.h"
#include <iostream>

CreditCard::CreditCard(std::string num, std::string holder, BankAccount* acc, double limit)
        : cardNumber(num), holderName(holder), linkedAccount(acc), creditLimit(limit), currentDebt(0.0) {}

bool CreditCard::validatePin(int pin) {
    std::string s = std::to_string(pin);
    if(s.size() == 4)
        return true;
    else
        return false;
}

void CreditCard::makePayment(double amount){
    if (amount > creditLimit - currentDebt) {
        throw InsufficientFundsException("Payment exceeds credit limit");
    }
    currentDebt += amount;
    std::cout << "Payment of " << amount << " made on card " << cardNumber << std::endl;
}

double CreditCard::getAvailableCredit() const {
    return creditLimit - currentDebt;
}

std::string CreditCard::getCardNumber() const {
    return cardNumber;
}