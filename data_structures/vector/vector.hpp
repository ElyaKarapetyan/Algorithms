#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector {
public:
    /*Adds a new element at the specified position*/
    void insert(const int index, const int value);

    /*Adds a new element at the end of the vector*/
    void push_back(int value);

    /*Removes an element from the specified position*/
    void erase(const int index);

    /*Removes the last element in the vector*/
    void pop_back();

    /*Returns the number of elements in the vector*/
    int size() const;

    /*Prints the current vector*/
    void printVector() const;

    /*Default constructor*/
    Vector();

    /*Parametrized constructor*/
    Vector(int size, int value);

    /*Copy constructor*/
    Vector(const Vector& object);

    /*Move constructor*/
    Vector(Vector&& object);

    /*Destructor*/
    ~Vector();

private:
    int* m_array;
    int m_size;
};

#endif
