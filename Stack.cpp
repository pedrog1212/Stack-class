#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack();
    ~Stack();

    void push(int x);
    int pop();
    int peek(int pos);
    bool isEmpty();
    int stackTop();
    void display();
};

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    Node* p = top;
    while (p != nullptr) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
}

void Stack::push(int x) {
    Node* newNode = new Node;
    if (newNode == nullptr) {
        cout << "Stack overflow" << endl;
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (top == nullptr) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    Node* temp = top;
    int x = temp->data;
    top = top->next;
    delete temp;
    return x;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

int Stack::stackTop() {
    if (isEmpty()) {
        return -1;
    }
    return top->data;
}

int Stack::peek(int pos) {
    if (isEmpty()) {
        return -1;
    }
    Node* p = top;
    for (int i = 0; p != nullptr && i < pos - 1; ++i) {
        p = p->next;
    }
    if (p != nullptr) {
        return p->data;
    }
    return -1; 
}

void Stack::display() {
    Node* p = top;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Stack stk;

    stk.push(7);
    stk.push(5);
    stk.push(9);
    stk.push(19);
    stk.display();

    cout << "Peek at position 3: " << stk.peek(3) << endl;  

    cout << "Popped element: " << stk.pop() << endl;
    stk.display();

    return 0;
}
