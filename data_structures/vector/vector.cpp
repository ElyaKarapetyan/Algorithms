#include <iostream>
#include "vector.hpp"

void Vector::insert(const int index, const int value) {
    // If the index out of range then stop the script
    if (0 > index || m_size < index) {
        std::cout << "\n\nERROR: The index should be between 0 and " << m_size << std::endl << std::endl;
        return;
    }

    // Copy the elements in the another temporary array
    int* tmp = m_array;
    // Creates a new array with one more size of the element
    m_array = new int[++m_size];
    // Inserts the elements into the new array until the specified index
    for (int i = 0; i < index; ++i) {
        m_array[i] = tmp[i];
    }

    // Inserts a new element at the specified position
    m_array[index] = value;

    // Inserts the last elements after the specific index
    for (int i = index + 1; i < m_size; ++i) {
        m_array[i] = tmp[i - 1];
    }

    // Deletes the temporary array
    delete[] tmp;
    tmp = nullptr;
}

void Vector::push_back(const int value) {
    insert(m_size, value);
}

void Vector::erase(const int index) {
    // If the vector is empty then stop the script
    if (0 == m_size) {
        std::cout << "\n\nWARNING: The Vector is empty!\n" << std::endl;
        return;
    }
    // If the index out of range then stop the script
    if (0 > index || m_size < index) {
        std::cout << "\n\nERROR: The index should be between 0 and " << m_size << std::endl << std::endl;
        return;
    }

    // Copy the elements in the another temporary array
    int* tmp = m_array;

    // Creates a new array with one less size of the element
    m_array = new int[--m_size];
    for (int i = 0; i < m_size; ++i) {
        // Inserts the elements into the new array until the specified index
        // then jump over the specified element and continue the inserting
        if (i < index) {
            m_array[i] = tmp[i];
        } else {
            m_array[i] = tmp[i + 1];
        }
    }

    // Deletes the temporary array
    delete[] tmp;
    tmp = nullptr;
}

void Vector::pop_back() {
    // If the vector is empty then stop the script
    if (0 == m_size) {
        std::cout << "\n\nWARNING: The Vector is empty!\n" << std::endl;
        return;
    }
    erase(m_size - 1);
}

int Vector::size() const {
    return m_size;
}

void Vector::printVector() const {
    if (0 == m_size) {
        return;
    }
    std::cout << "\n\nVector -> ";
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

// Creates the vector with 0 size
Vector::Vector() : m_array(nullptr)
         , m_size(0) {};

// Creates the vector with the specific size and value
Vector::Vector(const int size, const int value) : m_size(size) {
    m_array = new int[size];
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = value;
    }
}

// Creates the vector which is a copy of another vector
Vector::Vector(const Vector& object) {
    m_size = object.m_size;
    m_array = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = object.m_array[i];
    }
}

// Creates the vector which is a copy of another vector
Vector::Vector (Vector&& object) {
    m_array = object.m_array;
    m_size = object.m_size;
    object.m_size = 0;
    object.m_array = nullptr;
}

// Removes the vector
Vector::~Vector() {
    delete[] m_array;
    m_array = nullptr;
}