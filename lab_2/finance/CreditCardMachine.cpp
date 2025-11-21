#include "CreditCardMachine.h"

CreditCardMachine::CreditCardMachine(const std::string &id, bool on, int code): terminalId(id), online(on), lastResponseCode(code) {}
bool CreditCardMachine::authorize(const std::string &card, double amount) {
    if (!online) throw PaymentDeclinedException();
    if (card.size() < 12) { lastResponseCode = 400; return false; }
    lastResponseCode = 200;
    return true;
}
void CreditCardMachine::setOnline(bool v){
    online = v;
}
int CreditCardMachine::lastCode() const {
    return lastResponseCode;
}

