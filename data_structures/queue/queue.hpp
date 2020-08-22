#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue {
public:

    /*Returns whether the queue is empty*/
    bool empty() const;

    /*Returns whether the queue is full*/
    bool isFull() const;

    /*Returns the number of elements in the queue*/
    int size() const;

    /*Inserts a new element at the end of the queue, after its current last element*/
    void push(const int value);

    /*Removes the next element in the queue*/
    void pop();

    /*Returns a reference to the next element in the queue*/
    int& front();

    /*Returns a reference to the last element in the queue*/
    int& back();

    /*Prints the Queue*/
    void print() const;

    /*Default constructor*/
    Queue();

    /*Parametrized constructor*/
    Queue(const int size);

    /*Copy constructor*/
    Queue(const Queue& object);

    /*Move constructor*/
    Queue(Queue&& object);

    /*Destructor*/
    ~Queue();

private:
    int* m_array;
    int m_size;
    int m_front;
    int m_rear;
};

#endif
