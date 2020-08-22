#include <iostream>
#include "stack.hpp"

void isValue(int& number) {
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "\nPlease enter the integer number: ";
        std::cin >> number;
    }
}

void chooseFunction(const int function, Stack* stack) {
    int index = 0;
    int value = 0;
    switch (function) {
        case 1 :
            std::cout << "\nEnter the value: ";
            std::cin >> value;
            isValue(value);
            stack->push(value);
            stack->printStack();
            break;
        case 2 :
            stack->pop();
            stack->printStack();
            break;
        case 3 :
            std::cout << "\n\nSize of stack is " << stack->size() << std::endl << std::endl;
            break;
        case 4 :
            stack->empty() ? std::cout << "\n\nThe stack is empty!\n\n" : std::cout << "\n\nThe stack isn't empty!\n\n";
            break;
        default :
            std::cout << "\n\nERROR: Invalid function chose!\n" << std::endl;
            break;
    }
}

int main() {
    Stack* stack = new Stack(5, 7);
    int function = 0;
    std::cout << "\nThe inital Stack is : ";
    do {
        stack->printStack();
        std::cout << "\nPlease choose of the following functions" << std::endl << std::endl;
        std::cout << "1. push(value)\n2. pop()\n3. size()\n4. empty()\n";
        std::cout << "\n\nEnter 0 for exit or Choose the function: ";
        std::cin >> function;
        if (0 == function) {
            return 0;
        }
        isValue(function);
        chooseFunction(function, stack);
    } while (0 != function);
    return 0;
}
