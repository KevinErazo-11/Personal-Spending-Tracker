#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>
#include <string>
#include <sstream>

int getValidatedInt(int min, int max) {
    int value;
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        if (ss >> value && !(ss >> line)) {  
            if (value >= min && value <= max) {
                return value;
            } else {
                std::cout << "Error: The number must be between " << min << " and " << max << ". Try again: ";
            }
        } else {
            std::cout << "Invalid input. Please enter an integer: ";
        }
    }
}


double getValidatedDouble(double min, double max) {
    double value;
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        if (ss >> value && !(ss >> line)) {  
            if (value >= min && value <= max) {
                return value;
            } else {
                std::cout << "Error: The number must be between " << min << " and " << max << ". Try again: ";
            }
        } else {
            std::cout << "Invalid input. Please enter a valid number: ";
        }
    }
}

<<<<<<< HEAD

=======
>>>>>>> a77ca22 (Update)
#endif
