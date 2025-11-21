#include "Payment.h"

Payment::Payment(double a, const std::string &m): amount(a), method(m), confirmed(false) {}
void Payment::processCash(){
    confirmed = true;
}
void Payment::processCard(const std::string &cardNumber) {
    if (cardNumber.empty() || amount > 10000)
        throw PaymentDeclinedException();
    confirmed = true;
}
bool Payment::isConfirmed() const {
    return confirmed;
}

