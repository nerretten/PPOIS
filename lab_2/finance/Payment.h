#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include "../exceptions/PaymentDeclinedException.h"
#include <stdexcept>
#include <cstring>

class Payment {
private:
    double amount;
    std::string method;
    bool confirmed;
public:
    Payment(double a, const std::string &m);
    void processCash();
    void processCard(const std::string &cardNumber);
    bool isConfirmed() const;
};
#endif

