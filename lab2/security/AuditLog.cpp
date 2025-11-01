// AuditLog.cpp
#include "AuditLog.h"
#include <iostream>
#include <fstream>

void AuditLog::logAction(std::string action, std::string actor) {
    Date now(2025, 10, 29); // Текущая дата
    LogEntry entry{now, action, actor};
    entries.push_back(entry);
    std::cout << "Logged: " << actor << " performed '" << action << "' at " << now.toString() << std::endl;
}

void AuditLog::exportLogs(std::string filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Timestamp,Action,Actor\n";
        for (const LogEntry& e : entries) {
            file << e.timestamp.toString() << "," << e.action << "," << e.actor << "\n";
        }
        file.close();
        std::cout << "Audit logs exported to " << filename << std::endl;
    } else {
        std::cout << "Could not open file: " << filename << std::endl;
    }
}

std::vector<AuditLog::LogEntry> AuditLog::getEntriesByActor(std::string actor) const {
    std::vector<LogEntry> result;
    for (const LogEntry& e : entries) {
        if (e.actor == actor) {
            result.push_back(e);
        }
    }
    return result;
}

void AuditLog::printLogs() const {
    std::cout << "=== Audit Log ===" << std::endl;
    for (const LogEntry& e : entries) {
        std::cout << e.timestamp.toString() << " | " << e.actor << " | " << e.action << std::endl;
    }
}