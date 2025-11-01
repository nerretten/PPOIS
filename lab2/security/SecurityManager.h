#ifndef SECURITYMANAGER_H
#define SECURITYMANAGER_H

#include "AuditLog.h"
#include <vector>
#include <string>

class SecurityManager {
private:
    AuditLog* audit;
    std::vector<std::string> blockedUsers;

public:
    SecurityManager(AuditLog* log);
    void blockUser(std::string user);
    void unblockUser(std::string user);
    void logSecurityEvent(std::string event, std::string user);
    void printBlockedUsers() const;
};

#endif // SECURITYMANAGER_H