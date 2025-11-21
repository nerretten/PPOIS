#ifndef DIAGNOSTIC_FAILURE_EXCEPTION_H
#define DIAGNOSTIC_FAILURE_EXCEPTION_H
#include "WorkshopException.h"
class DiagnosticFailureException : public WorkshopException {
public:
    DiagnosticFailureException(): WorkshopException("Diagnostic tool failure") {}
};
#endif

