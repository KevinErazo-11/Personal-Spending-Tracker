#include "Menu.h"
#include "utils.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <fstream>  

void Menu::showBalanceGraph() {
    std::vector<double> balances = manager.getBalanceOverTime();

    if (balances.empty()) {
        std::cout << "There are no transactions to show.\n";
        return;
    }

    exportBalancesToCSV(balances);

    std::string command = "python show_balance.py " + balanceFilename; 
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Error running Python script to show the graph.\n";
    }
}

void Menu::exportBalancesToCSV(const std::vector<double>& balances) {
    std::ofstream file(balanceFilename);
    file << "Transaction,Balance\n";
    for (size_t i = 0; i < balances.size(); ++i) {
        file << (i + 1) << "," << balances[i] << "\n";
    }
    file.close();
}

void Menu::showMainMenu() const {
    std::cout << "\n--- Personal Finance Manager ---\n";
    std::cout << "1. Add Transaction\n";
    std::cout << "2. Show Transaction History\n";
    std::cout << "3. Show Balance\n";
    std::cout << "4. Show Expenses by Category\n";
    std::cout << "5. Show Monthly Summary\n";
    std::cout << "6. Save to File\n";
    std::cout << "7. Load from File\n";
    std::cout << "8. Show Balance Graph\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

void Menu::addTransaction() {
    std::cout << "Enter type (0 = Income, 1 = Expense): ";
    int typeInt = getValidatedInt(0, 1);

    std::cout << "Enter amount: ";
    double amount = getValidatedDouble(0.01, 1e9);

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::string date;
    std::getline(std::cin, date);

    std::cout << "Enter category: ";
    std::string category;
    std::getline(std::cin, category);

    std::cout << "Enter description: ";
    std::string description;
    std::getline(std::cin, description);

    Transaction t(static_cast<TransactionType>(typeInt), amount, date, category, description);
    manager.addTransaction(t);

    std::cout << "Transaction added successfully.\n";
}

void Menu::showTransactionHistory() const {
    manager.showHistory();
}

void Menu::showBalance() const {
    double balance = manager.calculateBalance();
    std::cout << "Current Balance: " << balance << "\n";
}

void Menu::showExpensesByCategory() const {
    manager.showExpensesByCategory();
}

void Menu::showMonthlySummary() const {
    std::cout << "Enter month (MM): ";
    std::string month;
    std::getline(std::cin, month);

    // Validación simple del formato MM
    if (month.size() != 2 || month[0] < '0' || month[0] > '1' || month[1] < '0' || month[1] > '9') {
        std::cout << "Invalid month format. Please enter MM (e.g., 01, 12).\n";
        return;
    }

    manager.showMonthlySummary(month);
}

void Menu::saveToFile() const {
    std::cout << "Enter filename to save (e.g., data.csv): ";
    std::string filename;
    std::cin >> filename;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    manager.saveTransactionsToFile(filename);

    const_cast<Menu*>(this)->currentFilename = filename;
}

void Menu::loadFromFile() {
    std::cout << "Enter filename to load (e.g., data.csv): ";
    std::string filename;
    std::cin >> filename;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    manager.loadTransactionsFromFile(filename);

    currentFilename = filename;
}

void Menu::run() {
    int option;

    do {
        showMainMenu();
        option = getValidatedInt(0, 8);

        switch (option) {
            case 1: addTransaction(); break;
            case 2: showTransactionHistory(); break;
            case 3: showBalance(); break;
            case 4: showExpensesByCategory(); break;
            case 5: showMonthlySummary(); break;
            case 6: saveToFile(); break;
            case 7: loadFromFile(); break;
            case 8: showBalanceGraph(); break;
            case 0: std::cout << "Exiting program.\n"; break;
            default: std::cout << "Invalid option. Try again.\n";
        }

    } while (option != 0);
}


