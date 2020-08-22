#include "list.hpp"


int  List::size() const {
    int size = 0;
    Node* current = m_head;
    // go through all the elements and calculate the count of elements
    while (nullptr != current) {
        ++size;
        current = current->m_next;
    }
    return size;
}

bool List::empty() const {
    // If the size is 0 then the list is empty
    return (size() == 0);
}

void List::push_front(const int value) {
    // Creates a new elemenet with the value
    Node* newNode = new Node(value);
    // to make head the newly created element
    newNode->m_next = m_head;
    m_head = newNode;
}

void List::push_back(const int value) {
    // Creates a new elemenet with the value
    Node* newNode = new Node(value);
    // If the list is empty then the newly created element is both head and tail
    if (nullptr == m_head) {
        m_head = newNode;
        return;
    }
    // go through all the elements and make tail the newly created element
    Node* current = m_head;
    while (nullptr != current->m_next) {
        current = current->m_next;
    }
    current->m_next = newNode;
}

void List::insert(const int index, const int value) {
    int listSize = size();
    // If the list is empty then the script stops
    if (index > listSize) {
        std::cout << "\n\nSize of list: " << listSize << "\tInvalid Index!\n" << std::endl;
        return;
    }
    // Creates a new element with the value
    Node* newNode = new Node(value);

    // If index is 0 then element should be insert as first element
    if (0 == index) {
        push_front(value);
        return;
    }

    // If the list is empty then the element should be head
    if (nullptr == m_head) {
        m_head = newNode;
        return;
    }

    // If the list contains only one element then the element should be next of head
    if (nullptr == m_head->m_next) {
        m_head->m_next = newNode;
        return;
    }

    // Creates a pointer to go to the necessary position and inserts elements
    Node* current = m_head;
    int i = 0;
    // Steps until specific element
    while (i < index - 1) {
        current = current->m_next;
        ++i;
    }
    // Inserts new element
    newNode->m_next = current->m_next;
    current->m_next = newNode;
}

void List::pop_front() {
    // If the list is empty then the script stops
    if (nullptr == m_head) {
        std::cout << "\n\nERROR: List is empty";
        return;
    }
    Node* tmp = m_head;
    m_head = m_head->m_next;
    delete tmp;
    tmp = nullptr;
}

void List::pop_back() {
    // If the list is empty then the script stops
    if (nullptr == m_head) {
        std::cout << "\n\nERROR: List is empty!!!\n" << std::endl;
        return;
    }

    // If there is a single element then removes the head
    if (nullptr == m_head->m_next) {
        delete m_head;
        m_head = nullptr;
        return;
    }

    // Creates pointer to get the last element
    Node* current = m_head->m_next;
    // Creates pointer to get the previous of last element
    Node* tmp = m_head;

    // go through all the elements and get the last one
    while (nullptr != current->m_next) {
        current = current->m_next;
        tmp = tmp->m_next;
    }

    //Removes the last element
    delete current;
    current = nullptr;
    tmp->m_next = nullptr;

}

void List::erase(const int index) {
    // If the index is out of size then the script stops
    int listSize = size();
    if (index > listSize) {
        std::cout << "Size of list: " << listSize << "\tInvalid Index!\n" << std::endl;
        return;
    }

    // If the index is 0 then remove the first elemnet
    if (0 == index) {
        pop_front();
        return;
    }

    // If the list is empty then the script stops
    if (nullptr == m_head) {
        std::cout << "\nList is empty!!!\n" << std::endl;
        return;
    }

    // If there is a single element then removes the head
    if (nullptr == m_head->m_next) {
        delete m_head;
        m_head = nullptr;
        return;
    }

    // Creates pointer to get the previous of specific index
    Node* current = m_head;
    int i = 0;

    /// go through all the elements until specific index
    while (i < index - 1) {
        current = current->m_next;
        ++i;
    }

    // Removes the element
    Node* tmp = current->m_next;
    current->m_next = tmp->m_next;
    delete tmp;
    tmp = nullptr;
}

void List::clear() {
    // Removes all the data of list
    while (nullptr != m_head) {
        pop_front();
    }
}

void List::printList() const {
    std::cout << "\nList ---> ";
    Node* current = m_head;
    while (nullptr != current) {
        std::cout << current->m_value << " ";
        current = current->m_next;
    }
    std::cout << std::endl << std::endl;
}

// Creates the empty list
List::List() : m_head(nullptr) {}

// Creates the list which is a copy of another list
List::List(const List& object) {
    Node* current = object.m_head;
    while (nullptr != current) {
        push_back(current->m_value);
        current = current->m_next;
    }
}

// Creates the list which is a copy of another list
List::List(List&& object) {
    m_head = object.m_head;
    object.m_head = nullptr;
}

List::~List() {
   clear();
}