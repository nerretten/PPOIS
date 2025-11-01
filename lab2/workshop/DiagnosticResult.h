#ifndef DIAGNOSTICRESULT_H
#define DIAGNOSTICRESULT_H

#include "../operations//DiagnosticReport.h"
#include <string>
#include <vector>

class DiagnosticResult {
private:
    DiagnosticReport* report;
    std::vector<std::string> recommendedActions;
    bool isCritical;

public:
    DiagnosticResult(DiagnosticReport* rep);
    void addRecommendedAction(std::string action);
    void setCritical(bool critical);
    void printResult() const;
    std::string getSummary() const;
};

#endif // DIAGNOSTICRESULT_H