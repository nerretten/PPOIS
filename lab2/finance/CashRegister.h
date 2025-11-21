#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H
#include <string>
#include <iostream>
#include <stdexcept>
class CashRegister {
private:
    double drawerAmount;
    int transactionsToday;
    std::string location;
public:
    CashRegister(double start, const std::string &loc);
    void openDrawer();
    void closeDrawer();
    void registerTransaction(double amount);
};
#endif

