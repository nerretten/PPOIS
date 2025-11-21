#include "CashRegister.h"

CashRegister::CashRegister(double start, const std::string &loc)
        : drawerAmount(start), transactionsToday(0), location(loc) {
    if (drawerAmount < 0.0) {
        drawerAmount = 0.0;
    }
}

void CashRegister::openDrawer() {
    std::cout << "[CashRegister] Drawer opened at " << location << std::endl;
}

void CashRegister::closeDrawer() {
    std::cout << "[CashRegister] Drawer closed at " << location << std::endl;
}

void CashRegister::registerTransaction(double amount) {
    if (amount <= 0.0) {
        throw std::invalid_argument("Transaction amount must be positive");
    }
    drawerAmount += amount;
    transactionsToday++;
}