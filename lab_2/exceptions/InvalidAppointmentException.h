#ifndef INVALID_APPOINTMENT_EXCEPTION_H
#define INVALID_APPOINTMENT_EXCEPTION_H
#include "WorkshopException.h"
class InvalidAppointmentException : public WorkshopException {
public:
    InvalidAppointmentException(): WorkshopException("Invalid appointment") {}
};
#endif


