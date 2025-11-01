#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(std::string accNum, std::string owner, double bal, std::string curr)
        : accountNumber(accNum), balance(bal), ownerName(owner), currency(curr) {}

void BankAccount::deposit(double amount) {
    balance += amount;
    std::cout << "Deposited " << amount << " " << currency << " to account " << accountNumber << std::endl;
}

void BankAccount::withdraw(double amount){
    if (balance < amount) {
        throw InsufficientFundsException("Withdrawal of " + std::to_string(amount) + " exceeds balance of " + std::to_string(balance));
    }
    balance -= amount;
    std::cout << "Withdrew " << amount << " " << currency << " from account " << accountNumber << std::endl;
}

void BankAccount::transferTo(BankAccount& target, double amount){
    try {
        this->withdraw(amount);
        target.deposit(amount);
        std::cout << "Transferred " << amount << " " << currency << " from " << accountNumber << " to " << target.getAccountNumber() << std::endl;
    } catch (InsufficientFundsException& e) {
        throw TransactionFailedException(e.what());
    }
}

double BankAccount::getBalance() const {
    return balance;
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getOwnerName() const {
    return ownerName;
}