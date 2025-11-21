#ifndef PART_NOT_FOUND_EXCEPTION_H
#define PART_NOT_FOUND_EXCEPTION_H
#include "WorkshopException.h"
class PartNotFoundException : public WorkshopException {
public:
    PartNotFoundException(): WorkshopException("Part not found") {}
    explicit PartNotFoundException(const std::string &m): WorkshopException(m) {}
};
#endif

