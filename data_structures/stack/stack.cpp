#include "stack.hpp"

void Stack::push(const int value) {
    if (empty()) {
        m_array[0] = value;
        ++m_size;
        return;
    }
    // Copy the elements in the another temporary array
    int* tmp = m_array;
    // Creates a new array with one more size of the element
    m_array = new int[++m_size];
    m_array[0] = value;
    // Inserts the elements into the new array until the specified index
    for (int i = 1; i < m_size; ++i) {
        m_array[i] = tmp[i - 1];
    }

    // Deletes the temporary array
    delete[] tmp;
    tmp = nullptr;
}

void Stack::pop() {
   // If the stack is empty then stop the script
    if (empty()) {
        std::cout << "\n\nWARNING: The Stack is empty!\n" << std::endl;
        return;
    }

    // Copy the elements in the another temporary array
    int* tmp = m_array;

    // Creates a new array with one less size of the element
    m_array = new int[--m_size];
    for (int i = 0; i < m_size; ++i) {
        // Inserts the elements except first into the new array
            m_array[i] = tmp[i + 1];
    }

    // Deletes the temporary array
    delete[] tmp;
    tmp = nullptr;
}

int Stack::size() const {
    return m_size;
}

bool Stack::empty() const {
    return 0 == m_size;
}

void Stack::printStack() const {
    if (empty()) {
        return;
    }
    std::cout << "\n\nStack -> ";
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_array[i] << " ";
    }
}

// Creates the stack with 0 size
Stack::Stack() : m_array(nullptr)
         , m_size(0) {};

// Creates the Stack with the specific size and value
Stack::Stack(const int size, const int value) : m_size(size) {
    m_array = new int[size];
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = value;
    }
}

// Creates the Stack which is a copy of another stack
Stack::Stack(const Stack& object) {
    m_size = object.m_size;
    m_array = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = object.m_array[i];
    }
}

// Creates the stack which is a copy of another stack
Stack::Stack(Stack&& object) {
    m_array = object.m_array;
    m_size = object.m_size;
    object.m_size = 0;
    object.m_array = nullptr;
}

// Removes the Stack
Stack::~Stack() {
    delete[] m_array;
    m_array = nullptr;
}
