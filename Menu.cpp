#include "Menu.h"
#include <iostream>
#include <limits>

void Menu::showMainMenu() const {
    std::cout << "\n--- Personal Finance Manager ---\n";
    std::cout << "1. Add Transaction\n";
    std::cout << "2. Show Transaction History\n";
    std::cout << "3. Show Balance\n";
    std::cout << "4. Show Expenses by Category\n";
    std::cout << "5. Show Monthly Summary\n";
    std::cout << "6. Save to File\n";
    std::cout << "7. Load from File\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

void Menu::addTransaction() {
    int typeInt;
    double amount;
    std::string date, category, description;

    std::cout << "Enter type (0 = Income, 1 = Expense): ";
    std::cin >> typeInt;

    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    std::cout << "Enter category: ";
    std::getline(std::cin, category);

    std::cout << "Enter description: ";
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
    std::string month;
    std::cout << "Enter month (MM): ";
    std::cin >> month;
    manager.showMonthlySummary(month);
}

void Menu::saveToFile() const {
    std::string filename;
    std::cout << "Enter filename to save (e.g., data.csv): ";
    std::cin >> filename;
    manager.saveToFile(filename);
}

void Menu::loadFromFile() {
    std::string filename;
    std::cout << "Enter filename to load (e.g., data.csv): ";
    std::cin >> filename;
    manager.loadFromFile(filename);
}

void Menu::run() {
    int option;

    do {
        showMainMenu();
        std::cin >> option;

        switch (option) {
            case 1: addTransaction(); break;
            case 2: showTransactionHistory(); break;
            case 3: showBalance(); break;
            case 4: showExpensesByCategory(); break;
            case 5: showMonthlySummary(); break;
            case 6: saveToFile(); break;
            case 7: loadFromFile(); break;
            case 0: std::cout << "Exiting program.\n"; break;
            default: std::cout << "Invalid option. Try again.\n";
        }

    } while (option != 0);
}
