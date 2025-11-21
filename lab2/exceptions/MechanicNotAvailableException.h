#ifndef MECHANIC_NOT_AVAILABLE_EXCEPTION_H
#define MECHANIC_NOT_AVAILABLE_EXCEPTION_H
#include "WorkshopException.h"
class MechanicNotAvailableException : public WorkshopException {
public:
    MechanicNotAvailableException(): WorkshopException("Mechanic not available") {}
};
#endif

