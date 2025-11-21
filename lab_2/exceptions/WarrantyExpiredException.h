#ifndef WARRANTY_EXPIRED_EXCEPTION_H
#define WARRANTY_EXPIRED_EXCEPTION_H
#include "WorkshopException.h"
class WarrantyExpiredException : public WorkshopException {
public:
    WarrantyExpiredException(): WorkshopException("Warranty expired") {}
};
#endif

