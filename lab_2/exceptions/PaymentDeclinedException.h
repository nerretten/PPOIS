#ifndef PAYMENT_DECLINED_EXCEPTION_H
#define PAYMENT_DECLINED_EXCEPTION_H
#include "WorkshopException.h"
class PaymentDeclinedException : public WorkshopException {
public:
    PaymentDeclinedException(): WorkshopException("Payment declined") {}
};
#endif

