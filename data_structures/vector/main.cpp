#include <iostream>
#include "vector.hpp"

void isValue(int& number) {
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "\nPlease enter the intager number: ";
        std::cin >> number;
    }
}

void chooseFunction(const int function, Vector& vector) {
    int index = 0;
    int value = 0;
    switch (function) {
        case 1 :
            std::cout << "\nEnter the index: ";
            std::cin >> index;
            isValue(index);
            std::cout << "\nEnter the value: ";
            std::cin >> value;
            isValue(value);
            vector.insert(index, value);
            vector.printVector();
            break;
        case 2 :
            std::cout << "\nEnter the value: ";
            std::cin >> value;
            isValue(value);
            vector.push_back(value);
            vector.printVector();
            break;
        case 3:
            std::cout << "\nEnter the index: ";
            std::cin >> index;
            isValue(index);
            vector.erase(index);
            vector.printVector();
            break;
        case 4 :
            vector.pop_back();
            vector.printVector();
            break;
        case 5 :
            std::cout << "\n\nSize of vector is " << vector.size() << std::endl << std::endl;
            break;
        default :
            std::cout << "\n\nERROR: Invalid function chose!\n" << std::endl;
            break;
    }
}

int main() {
    Vector vector;
    int function = 0;
    do {
        std::cout << "\nPlease choose on of the following functions" << std::endl << std::endl;
        std::cout << "1. insert(index, value)\n2. push_back()\n3. erase(index)\n4. pop_back()\n5. size()\n";
        std::cout << "\n\nEnter 0 for exit or Choose the function: ";
        std::cin >> function;
        if (0 == function) {
            return 0;
        }
        isValue(function);
        chooseFunction(function, vector);
    } while (0 != function);
    return 0;
}
