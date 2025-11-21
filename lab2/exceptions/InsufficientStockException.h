#ifndef INSUFFICIENT_STOCK_EXCEPTION_H
#define INSUFFICIENT_STOCK_EXCEPTION_H
#include "WorkshopException.h"
class InsufficientStockException : public WorkshopException {
public:
    InsufficientStockException(): WorkshopException("Insufficient stock") {}
};
#endif

