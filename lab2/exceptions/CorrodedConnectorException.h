#ifndef CORRODED_CONNECTOR_EXCEPTION_H
#define CORRODED_CONNECTOR_EXCEPTION_H
#include "WorkshopException.h"
class CorrodedConnectorException : public WorkshopException {
public:
    CorrodedConnectorException(): WorkshopException("Connector corroded") {}
};
#endif

