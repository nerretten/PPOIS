#include "DiagnosticResult.h"
#include <iostream>

DiagnosticResult::DiagnosticResult(DiagnosticReport* rep)
        : report(rep), isCritical(false) {}

void DiagnosticResult::addRecommendedAction(std::string action) {
    recommendedActions.push_back(action);
}

void DiagnosticResult::setCritical(bool critical) {
    isCritical = critical;
}

void DiagnosticResult::printResult() const {
    std::cout << "=== Diagnostic Result ===" << std::endl;
    report->printReport();
    std::cout << "Recommended Actions:" << std::endl;
    for (const std::string& a : recommendedActions) {
        std::cout << "  - " << a << std::endl;
    }
    std::cout << "Critical: " << (isCritical ? "Yes" : "No") << std::endl;
}

std::string DiagnosticResult::getSummary() const {
    return "Report ID: " + report->getReportId() + ", Critical: " + (isCritical ? "Yes" : "No");
}