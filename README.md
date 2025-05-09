# Personal-Spending-Tracker
PersonalFinanceManager is a C++ application that allows users to manage their personal finances. It provides functionality for recording transactions, viewing balances, analyzing expenses by category, saving information to files, and viewing monthly summaries.
## Features

- Add income and expense transactions
- Show complete transaction history
- Calculate financial balance
- Show total expenses by category
- Display monthly summary (income, expenses and balance)
- Save and load data from CSV files

## 📂 Project structure
- main.cpp // Program entry point
- Menu.h / Menu.cpp // Menu and user interaction
- FinanceManager.h / .cpp // Main financial management logic
- Transaction.h // Transaction definition

- ## How to compile

Open a terminal in the root of the project and run:

```bash
g++ main.cpp Menu.cpp FinanceManager.cpp -o PersonalFinanceManager.exe
```
Make sure you have the g++ compiler installed and that it is in your PATH variable.

## How to execute
From the terminal, run the generated file:
```bash
.\PersonalFinanceManager.exe
```

## CSV file format
Transactions are saved in the file in the following format:   
Type, Amount, Date, Category, Description.  
Example:  
- INCOME,1000.0,2025-05-06,Salary,Monthly Salary
- EXPENSE,50.0,2025-05-07, Meal, Lunch

## 🧑‍💻 Author
Kevin Erazo  
Project for the Advanced Programming course  
Yachay Tech University - 2025
