#include "FinanceManager.h"
#include "Transaction.h"
#include <fstream>
#include <iostream>
#include <map>

FinanceManager::FinanceManager() {
    
}

void FinanceManager::addTransaction(const Transaction& t) {
    transactions.push_back(t);
}

void FinanceManager::showHistory() const {
    if (transactions.empty()) {
        std::cout << "No transactions available.\n";
        return;
    }

    for (const auto& transaction : transactions) {
        std::cout << "Type: " << (transaction.getType() == INCOME ? "Income" : "Expense")
                  << ", Amount: " << transaction.getAmount()
                  << ", Date: " << transaction.getDate()
                  << ", Category: " << transaction.getCategory()
                  << ", Description: " << transaction.getDescription() << "\n";
    }
}

double FinanceManager::calculateBalance() const {
    double balance = 0.0;
    for (const auto& transaction : transactions) {
        if (transaction.getType() == INCOME) {
            balance += transaction.getAmount();
        } else {
            balance -= transaction.getAmount();
        }
    }
    return balance;
}

void FinanceManager::showExpensesByCategory() const {
    std::map<std::string, double> categoryTotals;

    for (const auto& transaction : transactions) {
        if (transaction.getType() == EXPENSE) {
            categoryTotals[transaction.getCategory()] += transaction.getAmount();
        }
    }

    if (categoryTotals.empty()) {
        std::cout << "No expenses available.\n";
    } else {
        for (const auto& entry : categoryTotals) {
            std::cout << "Category: " << entry.first << " - Total Expenses: " << entry.second << "\n";
        }
    }
}

void FinanceManager::showMonthlySummary(const std::string& month) const {
    double totalIncome = 0.0, totalExpenses = 0.0;

    for (const auto& transaction : transactions) {
        if (transaction.getDate().substr(5, 2) == month) {
            if (transaction.getType() == INCOME) {
                totalIncome += transaction.getAmount();
            } else {
                totalExpenses += transaction.getAmount();
            }
        }
    }

    std::cout << "Month: " << month << "\n";
    std::cout << "Total Income: " << totalIncome << "\n";
    std::cout << "Total Expenses: " << totalExpenses << "\n";
    std::cout << "Net Balance: " << (totalIncome - totalExpenses) << "\n";
}

void FinanceManager::saveToFile(const std::string& file) const {
    std::ofstream outFile(file);  

    if (!outFile.is_open()) {  
        std::cerr << "Error opening file for saving.\n";
        return;
    }

    for (const auto& transaction : transactions) {
        outFile << transaction.toCSV() << "\n";  
    }

    std::cout << "Transactions saved to file.\n";
    outFile.close();  
}

void FinanceManager::loadFromFile(const std::string& file) {
    std::ifstream inFile(file);  

    if (!inFile.is_open()) {  
        std::cerr << "Error opening file for loading.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        
        transactions.push_back(Transaction::fromCSV(line));  
    }

    std::cout << "Transactions loaded from file.\n";
    inFile.close();  
}
