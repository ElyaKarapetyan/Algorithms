#include "set.hpp"

void isValue(int& number) {
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "\nPlease enter the integer number: ";
        std::cin >> number;
    }
}

void chooseFunction(const int function, Set& set) {
    int index = 0;
    int value = 0;
    switch (function) {
        case 1 :
            std::cout << "\nEnter the value: ";
            std::cin >> value;
            isValue(value);
            set.insert(value);
            set.printSet();
            break;
        case 2 :
            std::cout << "\nEnter the value: ";
            std::cin >> value;
            isValue(value);
            set.erase(value);
            set.printSet();
            break;
        case 3:
            std::cout << "\nEnter the index: ";
            std::cin >> index;
            isValue(index);
            set.eraseByIndex(index);
            set.printSet();
            break;
        case 4 :
            std::cout << "\n\nSize of set is " << set.size() << std::endl << std::endl;
            break;
        default :
            std::cout << "\n\nERROR: Invalid function chose!\n" << std::endl;
            break;
    }
}

int main() {
    Set set;
    int function = 0;
    do {
        std::cout << "\nPlease choose on of the following functions" << std::endl << std::endl;
        std::cout << "1. insert(value)\n2. erase(value)\n3. erase(index)\n4. size()\n";
        std::cout << "\n\nEnter 0 for exit or Choose the function: ";
        std::cin >> function;
        if (0 == function) {
            return 0;
        }
        isValue(function);
        chooseFunction(function, set);
    } while (0 != function);
    return 0;
}
