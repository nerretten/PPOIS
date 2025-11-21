#ifndef INVALID_VIN_EXCEPTION_H
#define INVALID_VIN_EXCEPTION_H
#include "WorkshopException.h"
class InvalidVINException : public WorkshopException {
public:
    InvalidVINException(): WorkshopException("Invalid VIN") {}
};
#endif

