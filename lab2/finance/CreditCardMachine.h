#ifndef CREDIT_CARD_MACHINE_H
#define CREDIT_CARD_MACHINE_H
#include <string>
#include "../exceptions/PaymentDeclinedException.h"
#include <stdexcept>

class CreditCardMachine {
private:
    std::string terminalId;
    bool online;
    int lastResponseCode;
public:
    CreditCardMachine(const std::string &id, bool on, int code);
    bool authorize(const std::string &card, double amount);
    void setOnline(bool v);
    int lastCode() const;
};
#endif

