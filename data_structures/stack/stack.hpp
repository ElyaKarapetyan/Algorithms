#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

class Stack {
public:
    /*Inserts a new element at the top of the stack*/
    void push(const int value);

    /*Removes the element on top of the stack*/
    void pop();


    /*Returns whether the stack is empty*/
    int size() const;

    /*Returns the number of elements in the stack*/
    bool empty() const;

    /*Prints the Stack*/
    void printStack() const;

    /*Default constructor*/
    Stack();

    /*Parametrized constructor*/
    Stack(const int size, const int value);

    /*Copy constructor*/
    Stack(const Stack& object);

    /*Move constructor*/
    Stack(Stack&& object);

    /*Destructor*/
    ~Stack();

private:
    int* m_array;
    int m_size;
};

#endif
