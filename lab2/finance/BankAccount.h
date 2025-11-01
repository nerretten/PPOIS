#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include "../exceptions.h"

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    std::string ownerName;
    std::string currency;

public:
    BankAccount(std::string accNum, std::string owner, double bal = 0.0, std::string curr = "USD");
    void deposit(double amount);
    void withdraw(double amount);
    void transferTo(BankAccount& target, double amount);
    double getBalance() const;
    std::string getAccountNumber() const;
    std::string getOwnerName() const;
};

#endif // BANKACCOUNT_H