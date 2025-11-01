#include "DiagnosticReport.h"
#include <iostream>

DiagnosticReport::DiagnosticReport(std::string id, Car* c, DiagnosticTool* t)
        : reportId(id), car(c), tool(t) {}

void DiagnosticReport::addFinding(std::string finding) {
    findings.push_back(finding);
}

void DiagnosticReport::generateConclusion() {
    if (findings.empty()) {
        conclusion = "No issues found.";
    } else {
        conclusion = "Issues detected: ";
        for (const std::string& f : findings) {
            conclusion += f + "; ";
        }
    }
}

void DiagnosticReport::printReport() const {
    std::cout << "=== Diagnostic Report ===" << std::endl;
    std::cout << "ID: " << reportId << std::endl;
    std::cout << "Car: " << car->getVin() << std::endl;
    std::cout << "Findings:" << std::endl;
    for (const std::string& f : findings) {
        std::cout << "  - " << f << std::endl;
    }
    std::cout << "Conclusion: " << conclusion << std::endl;
}

std::string DiagnosticReport::getReportId() const {
    return reportId;
}