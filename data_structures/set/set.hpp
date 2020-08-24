#ifndef SET_HPP
#define SET_HPP

#include <iostream>

class Set {
public:
    /*Adds a new element*/
    void insert(const int value);

    /*Removes an element from the specified position*/
    void eraseByIndex(const int index);

    /*Removes an element*/
    void erase(const int value);

    /*Returns the number of elements in the Set*/
    int size() const;

    /*Prints the current Set*/
    void printSet() const;

    /*Default constructor*/
    Set();

    /*Parametrized constructor*/
    Set(int size, int value);

    /*Copy constructor*/
    Set(const Set& object);

    /*Move constructor*/
    Set(Set&& object);

    /*Destructor*/
    ~Set();

private:
    int* m_array;
    int m_size;

    /*Searches the element if it isn't exist in the Set so add a new element*/
    void binarySearchAndInsert(int low, int high, int key);

    /*Insert element in the the specified position*/
    void insert(const int value, const int index);

    /*Searches the element if it is exist in the Set so deletes the element*/
    void binarySearchAndErase(int low, int high, int key);
};

#endif
