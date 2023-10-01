#include "stack.h"
template class Stack<int>;
template class Stack<char>;

template <typename T>
Stack<T>::Stack() : topNode(nullptr), stackSize(0) {}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
void Stack<T>::push(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = topNode;
    topNode = newNode;
    stackSize++;
}

template <typename T>
void Stack<T>::pop() {
    if (!empty()) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        stackSize--;
    }
}

template <typename T>
T Stack<T>::top() const {
    if (!empty()) {
        return topNode->data;
    }
    return T();
}

template <typename T>
bool Stack<T>::empty() const {
    return stackSize == 0;
}

template <typename T>
int Stack<T>::size() const {
    return stackSize;
}

template <typename T>
void Stack<T>::clear() {
    while (!empty()) {
        pop();
    }
}
