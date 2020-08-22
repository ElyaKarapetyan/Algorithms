#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

class List {
public:
    /*Returns the number of elements in the list container*/
    int size() const;

    /*Returns whether the list container is empty*/
    bool empty() const;

    /*Inserts a new element at the beginning of the list, right before its current first element*/
    void push_front(const int value);

    /*Adds a new element at the end of the list container, after its current last element*/
    void push_back(const int value);

    /*Inserts a new elements before the element at the specified position*/
    void insert(const int index, const int value);

    /*Removes the first element in the list container, effectively reducing its size by one*/
    void pop_front();

    /*Removes the last element in the list container*/
    void pop_back();

    /*Removes from the list container either a single element*/
    void erase(const int index);

    /*Removes all elements from the list container*/
    void clear();

    /*Prints the List*/
    void printList() const;

    /*Default constructor*/
    List();

    /*Copy constructor*/
    List(const List& object);

    /*Move constructor*/
    List(List&& object);

    /*Destructor*/
    ~List();

private:
    struct Node {
        int m_value;
        Node* m_next;
        Node(int value, Node* next = nullptr) : m_value(value)
                                              , m_next(next) {}
    };
    Node* m_head;
};

#endif
