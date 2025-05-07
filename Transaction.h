#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <sstream>  

enum TransactionType { INCOME, EXPENSE };

class Transaction {
private:
    TransactionType type;
    double amount;
    std::string date; 
    std::string category;
    std::string description;

public:
    
    Transaction(TransactionType type, double amount, const std::string& date,
                const std::string& category, const std::string& description)
        : type(type), amount(amount), date(date), category(category), description(description) {}

    
    TransactionType getType() const { return type; }
    double getAmount() const { return amount; }
    std::string getDate() const { return date; }
    std::string getCategory() const { return category; }
    std::string getDescription() const { return description; }

    
    std::string toCSV() const {
        return std::to_string(type) + "," + std::to_string(amount) + "," + date + "," + category + "," + description;
    }

    
    static Transaction fromCSV(const std::string& csvLine) {
        std::stringstream ss(csvLine);
        std::string typeStr, amountStr, date, category, description;

        
        std::getline(ss, typeStr, ',');
        std::getline(ss, amountStr, ',');
        std::getline(ss, date, ',');
        std::getline(ss, category, ',');
        std::getline(ss, description);

        
        TransactionType type = static_cast<TransactionType>(std::stoi(typeStr));
        double amount = std::stod(amountStr);

        return Transaction(type, amount, date, category, description);
    }

};

#endif 
