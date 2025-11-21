#ifndef LIFT_OVERLOAD_EXCEPTION_H
#define LIFT_OVERLOAD_EXCEPTION_H
#include "WorkshopException.h"
class LiftOverloadException : public WorkshopException {
public:
    LiftOverloadException(): WorkshopException("Lift overload") {}
};
#endif

