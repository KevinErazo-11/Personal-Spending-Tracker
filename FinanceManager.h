#include <iostream>
#include <vector>
#include "Transaction.h"

class FinanceManager {
    private:
        std::vector<Transaction> transactions;
    
    public:
        FinanceManager();
        std::vector<double> getBalanceOverTime() const;
        void addTransaction(const Transaction& t);
        void showHistory() const;
        double calculateBalance() const;
        void showExpensesByCategory() const;
        void showMonthlySummary(const std::string& month) const;
    
        void saveToFile(const std::string& file) const;
        void loadFromFile(const std::string& file);
        void saveTransactionsToFile(const std::string& filename) const;
        void loadTransactionsFromFile(const std::string& filename);

};


