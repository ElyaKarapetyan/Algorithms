#include "queue.hpp"

bool Queue::empty() const {
    return m_front == m_rear;
}

bool Queue::isFull() const {
    return  m_rear == m_size;
}

int Queue::size() const {
    return m_rear - m_front;
}


void Queue::push(const int value) {
    // If the Queue is full then stop the script
    if (isFull()) {
        std::cout << "\n\nWARNING: The Queue is full! Can not add any element!\n" << std::endl;
        return;
    }
    // Adds a new element
    m_array[m_rear] = value;
    // Increase the rear index
    ++m_rear;
}

void Queue::pop() {
    // If the Queue is empty then stop the script
    if (empty()) {
        std::cout << "\n\nWARNING: The Queue is empty! Can not delete any element!\n" << std::endl;
        return;
    }
    // If there is only one element do decrease the rear and front index
    if (m_front == m_rear) {
        m_front = m_rear = -1;
        return;
    }
    // Increase the front index
    ++m_front;
}

int& Queue::front() {
    // If the Queue is empty then stop the script
    if (empty()) {
        std::cout << "\n\nWARNING: The Queue is empty! Ther isn't front value!\n" << std::endl;
        return m_rear;
    }
    // Returns the front element value
    return m_array[m_rear - 1];
}

int& Queue::back() {
    // If the Queue is empty then stop the script
    if (empty()) {
        std::cout << "\n\nWARNING: The Queue is empty! Ther isn't back value!\n" << std::endl;
        return m_front;
    }
    // Returns the back element value
    return m_array[m_front];
}


void Queue::print() const {
    // If the Queue is empty then stop the script
    if (empty()) {
        std::cout << "\n\nWARNING: The Queue is empty!\n" << std::endl;
        return;
    }
    std::cout << "\n\nQueue --> ";
    for (int i = m_front; i < m_rear; ++i) {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

// Creates the vector with 0 size
Queue::Queue() : m_array(nullptr)
               , m_size(0)
               , m_front(0)
               , m_rear(0) {}

// Creates the vector with the specific size
Queue::Queue(const int size) : m_size(size)
                             , m_front(0)
                             , m_rear(0) {
    m_array = new int[m_size];
}

// Creates the Queue which is a copy of another Queue
Queue::Queue(const Queue& object) {
    m_size = object.m_size;
    m_array = new int [m_size];
    m_front = object.m_front;
    m_rear = object.m_rear;
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = object.m_array[i];
    }
}

// Creates the Queue which is a copy of another Queue
Queue::Queue(Queue&& object) {
    m_array = object.m_array;
    m_size = object.m_size;
    object.m_size = 0;
    object.m_array = nullptr;
}

// Removes the Queue
Queue::~Queue() {
    delete[] m_array;
    m_array = nullptr;
}