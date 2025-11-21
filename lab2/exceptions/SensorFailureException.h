#ifndef SENSOR_FAILURE_EXCEPTION_H
#define SENSOR_FAILURE_EXCEPTION_H
#include "WorkshopException.h"
class SensorFailureException : public WorkshopException {
public:
    SensorFailureException(): WorkshopException("Sensor failure detected") {}
};
#endif

