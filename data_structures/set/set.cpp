#include "set.hpp"

void Set::insert(const int value) {
    if (0 == m_size) {
        m_array = new int[++m_size];
        m_array[0] = value;
        return;
    }
    Set::binarySearchAndInsert(0, m_size-1,value);
}

void Set::eraseByIndex(const int index) {
    // If the Set is empty then stop the script
    if (0 == m_size) {
        std::cout << "\n\nWARNING: The Set is empty!\n" << std::endl;
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

void Set::erase(const int value) {
    // If the Set is empty then stop the script
    if (0 == m_size) {
        std::cout << "\n\nWARNING: The Set is empty!\n" << std::endl;
        return;
    }

    // If the Set contains only one element so delete the set
    if (1 == m_size) {
        if (value == m_array[0]) {
            delete[] m_array;
            m_array = nullptr;
            m_size = 0;
        }
        return;
    }

    binarySearchAndErase(0, m_size - 1, value);
}

int Set::size() const {
    return m_size;
}

void Set::printSet() const {
    if (0 == m_size) {
        return;
    }
    std::cout << "\n\nSet -> ";
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

// Creates the Set with 0 size
Set::Set() : m_array(nullptr)
         , m_size(0) {};

// Creates the Set with the specific size and value
Set::Set(const int size, const int value) : m_size(size) {
    m_array = new int[size];
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = value;
    }
}

// Creates the Set which is a copy of another Set
Set::Set(const Set& object) {
    m_size = object.m_size;
    m_array = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = object.m_array[i];
    }
}

// Creates the Set which is a copy of another Set
Set::Set (Set&& object) {
    m_array = object.m_array;
    m_size = object.m_size;
    object.m_size = 0;
    object.m_array = nullptr;
}

// Removes the Set
Set::~Set() {
    delete[] m_array;
    m_array = nullptr;
}

void Set::binarySearchAndInsert(const int low, const int high, const int key) {
    // If element isn't exist in the Set so insert data
    if (high < low) {
        insert(key, low);
        return;
    }

    // Finds index of middle element
    int mid = (low + high) / 2;

    // If the key is middle element so stop the script
    if (key == m_array[mid]) {
        std::cout << "\n\n'" << key << "' is already exist in the Set! Please insert another value!\n\n";
        return;
    }

    // If the key is more than the middle element so repeat the steps for the right part of Set
    if (key > m_array[mid]) {
        return binarySearchAndInsert((mid + 1), high, key);
    }

    // If the key is less than the middle element so repeat the steps for the left part of Set
    return binarySearchAndInsert(low, (mid - 1), key);
}


void Set::insert(const int value, const int index) {

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

void Set::binarySearchAndErase(const int low, const int high, const int key) {
    // If element isn't exist in the Set so stop script
    if (high < low) {
        std::cout << "\n\n'" << key << "' isn't exist in the Set! Please try another value!\n\n";
        return;
    }

    // Finds index of middle element
    int mid = (low + high) / 2;

    // If the key is middle element so delete the element
    if (key == m_array[mid]) {
        eraseByIndex(mid);
        return;
    }

    // If the key is more than the middle element so repeat the steps for the right part of Set
    if (key > m_array[mid]) {
        return binarySearchAndErase((mid + 1), high, key);
    }

    // If the key is less than the middle element so repeat the steps for the left part of Set
    return binarySearchAndErase(low, (mid - 1), key);
}