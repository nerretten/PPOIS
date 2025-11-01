#include "PaymentProcessor.h"
#include "../exceptions.h"
#include <iostream>

bool PaymentProcessor::processPayment(CreditCard& card, double amount, int pin){
    if (!card.validatePin(pin)) {
        throw InvalidPasswordException("Incorrect PIN");
    }
    try {
        card.makePayment(amount);
        std::cout << "Payment of " << amount << " processed successfully." << std::endl;
        return true;
    } catch (InsufficientFundsException& e) {
        throw PaymentCancelledException(e.what());
    }
}

void PaymentProcessor::refund(BankAccount& account, double amount) {
    account.deposit(amount);
    std::cout << "Refund of " << amount << " processed to account " << account.getAccountNumber() << std::endl;
}