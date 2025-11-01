#include "FinancialReport.h"
#include <iostream>
#include <fstream>

FinancialReport::FinancialReport(std::vector<Invoice*> invs)
        : invoices(invs), totalRevenue(0.0), totalExpenses(0.0) {}

void FinancialReport::calculateTotals() {
    for (Invoice* i : invoices) {
        totalRevenue += i->getTotalAmount();
    }
    totalExpenses = totalRevenue * 0.3;
}

double FinancialReport::getNetProfit() const {
    return totalRevenue - totalExpenses;
}

void FinancialReport::exportToCSV(std::string filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "InvoiceID,Amount,Paid\n";
        for (Invoice* i : invoices) {
            file << i->getInvoiceId() << "," << i->getTotalAmount() << "," << (i->isOverdue() ? "No" : "Yes") << "\n";
        }
        file.close();
        std::cout << "Financial report exported to " << filename << std::endl;
    } else {
        std::cout << "Could not open file: " << filename << std::endl;
    }
}

void FinancialReport::printReport() const {
    std::cout << "=== Financial Report ===" << std::endl;
    std::cout << "Total Revenue: " << totalRevenue << std::endl;
    std::cout << "Total Expenses: " << totalExpenses << std::endl;
    std::cout << "Net Profit: " << getNetProfit() << std::endl;
}