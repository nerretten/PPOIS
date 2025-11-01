#ifndef FINANCIALREPORT_H
#define FINANCIALREPORT_H

#include "../finance/Invoice.h"
#include <vector>
#include <string>

class FinancialReport {
private:
    std::vector<Invoice*> invoices;
    double totalRevenue;
    double totalExpenses;

public:
    FinancialReport(std::vector<Invoice*> invs);
    void calculateTotals();
    double getNetProfit() const;
    void exportToCSV(std::string filename);
    void printReport() const;
};

#endif // FINANCIALREPORT_H