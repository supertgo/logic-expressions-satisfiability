#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();

    void push(const T& value);
    void pop();
    T top() const;
    bool empty() const;
    int size() const;
    void clear();

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* topNode;
    int stackSize;
};

#endif // STACK_H
