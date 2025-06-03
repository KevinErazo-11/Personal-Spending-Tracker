#include "FinanceManager.h"
#include "Transaction.h"
#include <fstream>
#include <iostream>
#include <map>
#include <thread>
#include <chrono>
#include <iomanip>    

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

std::vector<double> FinanceManager::getBalanceOverTime() const {
    std::vector<double> balances;
    double balance = 0.0;

    for (const auto& transaction : transactions) {
        if (transaction.getType() == INCOME) {
            balance += transaction.getAmount();
        } else {
            balance -= transaction.getAmount();
        }
        balances.push_back(balance);
    }

    return balances;

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


void FinanceManager::saveTransactionsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    file << "type,amount,date,category,description\n";
    for (const auto& t : transactions) {
        file << t.toCSV() << "\n";
    }
    file.close();
}

<<<<<<< HEAD
=======
void printProgressBar(size_t progress, size_t total) {
    const int barWidth = 50;
    float ratio = static_cast<float>(progress) / total;
    int pos = static_cast<int>(barWidth * ratio);
    const char animation[] = "|/-\\";
    char animChar = animation[progress % 4];

    const std::string reset = "\033[0m";

    std::cout << "[";  
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << animChar;
        else
            std::cout << " ";
    }
    std::cout << "] " << std::setw(3) << int(ratio * 100.0) << "%\r" << reset;
    std::cout.flush();

    std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

>>>>>>> a77ca22 (Update)

void FinanceManager::loadTransactionsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }
    transactions.clear();

<<<<<<< HEAD
    std::string line;
    
    if (std::getline(file, line)) {
        if (line.find("type") == std::string::npos) {
            transactions.push_back(Transaction::fromCSV(line));
=======
    std::vector<std::string> lines;
    std::string line;

    
    if (std::getline(file, line)) {
        if (line.find("type") != std::string::npos) {
            
        } else {
            lines.push_back(line);
>>>>>>> a77ca22 (Update)
        }
    }

    while (std::getline(file, line)) {
<<<<<<< HEAD
        if (line.empty()) continue;
        transactions.push_back(Transaction::fromCSV(line));
    }
    file.close();
}

=======
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    file.close();

    size_t total = lines.size();
    for (size_t i = 0; i < total; ++i) {
        transactions.push_back(Transaction::fromCSV(lines[i]));
        printProgressBar(i + 1, total);
    }

    std::cout << "\nLoaded " << total << " transactions from file.\n";
}
>>>>>>> a77ca22 (Update)
