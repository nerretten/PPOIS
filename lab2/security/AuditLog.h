#ifndef AUDITLOG_H
#define AUDITLOG_H

#include <vector>
#include <string>
#include "../utilities/Date.h"

class AuditLog {
private:
    struct LogEntry {
        Date timestamp;
        std::string action;
        std::string actor;
    };
    std::vector<LogEntry> entries;

public:
    void logAction(std::string action, std::string actor);
    void exportLogs(std::string filename);
    std::vector<LogEntry> getEntriesByActor(std::string actor) const;
    void printLogs() const;
};

#endif // AUDITLOG_H