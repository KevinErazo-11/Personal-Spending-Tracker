#pragma once
#include "FinanceManager.h"

class Menu {
private:
    FinanceManager manager;

    void showMainMenu() const;
    void addTransaction();
    void showTransactionHistory() const;
    void showBalance() const;
    void showExpensesByCategory() const;
    void showMonthlySummary() const;
    void saveToFile() const;
    void loadFromFile();

public:
    void run();
};
