// Write a program to implement a stack using a linked list. The stack should have operations like push(), pop(), top(), isEmpty(). 
// Queries:
// 1 x will represent to push integer x to the stack
// 2 will represent to pop the top element
// 3 will represent to print the stack top
// 4 will represent to print the entire stack

// Input Format:
// Number of queries q
// q lines representing the queries

// For example:
// Input:
// 5
// 1 10
// 1 20
// 3
// 2
// 4

// 5 indicates the number of queries
// 1 10 indicates push 10
// 1 20 indicates push 20
// 3 indicates print top element of the stack, which is 20
// 2 indicates pop the top element, that is, pop 20
// 4 indicates printing the entire stack

// Note: Pop does not require printing the topmost element. You have to remove it. For an empty stack, you have to print "Stack is empty\n"

#include <iostream>
using namespace std;

// Node class representing each element in the stack
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Stack class to handle stack operations
class Stack {
private:
    Node* topNode; // Pointer to the top node in the stack

public:
    // Constructor to initialize stack
    Stack() {
        topNode = nullptr;
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Function to push an element onto the stack
    void push(int x) {
        Node* n = new Node(x);
        
        n->next = topNode;        
        topNode = n;
    }

    // Function to pop the top element from the stack
    void pop() {
        
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }
        
        topNode = topNode->next;
    }

    // Function to get the top element of the stack
    int top() {
        
        return topNode->data;
    }

    // Function to print all elements of the stack
    void printStack() {
        Node* x = topNode;
        
        while(x != nullptr)
        {
            cout << x->data << " ";
            x = x->next;
        }
        cout << endl;
    }
};

// Main function to process queries
int main() {
    Stack stack;
    int q;
    cin >> q; // Number of queries
    
    while(q--)
    {
        int n;
        cin>>n;
        
        if (n==1)
        {
            int num;
            cin>>num;
            
            stack.push(num);
        }
        else if(n == 2)
        {
            stack.pop();
        }
        else if (n == 3)
        {
            cout << stack.top() << endl;
        }
        else if (n == 4)
        {
            stack.printStack();
        }
    }
    
    
    return 0;
}
