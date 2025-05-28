#pragma once
#include "FinanceManager.h"

class Menu {
private:
    FinanceManager manager;

    std::string balanceFilename = "balances.csv";
    void showMainMenu() const;
    void addTransaction();
    void showTransactionHistory() const;
    void showBalance() const;
    void showExpensesByCategory() const;
    void showMonthlySummary() const;
    void saveToFile() const;
    void loadFromFile();
    void showBalanceGraph();
    std::string currentFilename = "data.csv"; 
    void exportBalancesToCSV(const std::vector<double>& balances);

public:
    void run();
};
