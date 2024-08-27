// Write a program to implement two stacks using a single array. Design a data structure that supports two stacks and manages their elements. 
// Each stack has a push operation to add an element and a pop operation to remove the top element.
// Implement following functions:
// initialize(): Initialize the data structure with a given size for the array.
// push1(): Push an element onto the first stack.
// push2(): Push an element onto the second stack.
// pop1(): Pop an element from the first stack.
// pop2(): Pop an element from the second stack.
// printboth(): Print the elements of both stacks.

// If the stack is overflow or underflow, print 1 or -1 respectively.

// Input Format:
// Number of elements in Stack 1
// Elements of Stack 1
// Number of elements in Stack 2
// Elements in Stack 2

// Output Format:
// Print Stack 1
// Print Stack 2
// Output after performing pop1() operation.
// Output after performing pop2() operation.
// Print Stack 1
// Print Stack 2


#include <iostream>
#define MAX_SIZE 100  // Define the maximum size of the array

using namespace std;

// Class representing two stacks using a single array
class TwoStacks {
    int arr[MAX_SIZE];
    int top1; // Top for the first stack
    int top2; // Top for the second stack

public:
    // Constructor to initialize the two stacks
    TwoStacks() {
        initialize();
    }

    // Function to initialize the two stacks
    void initialize() {
        // TODO: Initialize top1 and top2
        top1 = -1;
        top2 = MAX_SIZE;
    }

    // Function to push an element onto the first stack
    void push1(int x) {
        // TODO: Implement the logic to push an element onto the first stack
        // Ensure that you check for overflow
        if (isFull())
        {
            cout << 1 << endl;
            return;
        }
        
        top1++;
        arr[top1] = x;
    }

    // Function to push an element onto the second stack
    void push2(int x) {
        // TODO: Implement the logic to push an element onto the second stack
        // Ensure that you check for overflow
        
        if (isFull())
        {
            cout << 1 << endl;
            return;
        }
        
        top2--;
        arr[top2] = x;
    }

    // Function to pop an element from the first stack
    int pop1() {
        // TODO: Implement the logic to pop an element from the first stack
        // Ensure that you check for underflow
        
        if (isEmpty())
        {
            return -1;
        }
        
        cout << arr[top1--] << endl;;
        
    }

    // Function to pop an element from the second stack
    int pop2() {
        // TODO: Implement the logic to pop an element from the second stack
        // Ensure that you check for underflow
        
        if (isEmpty())
        {
            return -1;
        }
        
        cout << arr[top2++] << endl;
    }

    // Function to print the elements of both stacks
    void printBoth() {
        // TODO: Implement the logic to print both stacks
        for (int i = 0; i <= top1; i++)
        {
            cout << arr[i] << " ";
        }
        
        cout << endl;
        
        for (int i = MAX_SIZE-1; i >= top2; i--)
        {
            cout << arr[i] << " ";
        }
        
        cout << endl;
    }
    
    bool isEmpty()
    {
        if (top1 == -1 && top2 == MAX_SIZE)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isFull()
    {
        if (top1 == top2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Main function
int main() {
    TwoStacks ts;
    ts.initialize();

    int n1, n2, x;
    
    cin>>n1;
    
    for (int i = 0; i < n1; i++)
    {
        cin>>x;
        ts.push1(x);
    }
    
    cin>>n2;
    
    for (int i = 0; i < n2; i++)
    {
        cin>>x;
        ts.push2(x);
    }

    // TODO: Add user input logic for the number of elements and elements for both stacks
    // Use push1 and push2 to add elements to the stacks

    // TODO: Perform a series of stack operations like pop and print
    
    ts.printBoth();
    
    ts.pop1();
    ts.pop2();
    
    ts.printBoth();

    return 0;
}
