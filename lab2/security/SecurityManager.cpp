#include "SecurityManager.h"
#include <iostream>

SecurityManager::SecurityManager(AuditLog* log) : audit(log) {}

void SecurityManager::blockUser(std::string user) {
    blockedUsers.push_back(user);
    audit->logAction("Block User", user);
    std::cout << "User " << user << " blocked." << std::endl;
}

void SecurityManager::unblockUser(std::string user) {
    auto it = std::find(blockedUsers.begin(), blockedUsers.end(), user);
    if (it != blockedUsers.end()) {
        blockedUsers.erase(it);
        audit->logAction("Unblock User", user);
        std::cout << "User " << user << " unblocked." << std::endl;
    }
}

void SecurityManager::logSecurityEvent(std::string event, std::string user) {
    audit->logAction(event, user);
}

void SecurityManager::printBlockedUsers() const {
    std::cout << "=== Blocked Users ===" << std::endl;
    for (const std::string& u : blockedUsers) {
        std::cout << "  - " << u << std::endl;
    }
}