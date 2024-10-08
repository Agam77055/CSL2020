// A stack of integers is given. The task is to sort the elements in ascending order using recursion. 
// Implement the following functions:
// createStack(): Initialize an empty stack.
// isEmpty(): Check if the stack is empty.
// push(): Push an integer onto the stack.
// pop(): Pop the top element from the stack.
// printStack(): Print the elements of the stack.
// sortedInsert(): A recursive function that inserts an element at the correct position in a sorted stack.
// sortStack(): A recursive function that sorts the given stack in ascending order using the sortedInsert function.
// NOTE : You may store the elements in the stack in any of the sorted order (ascending or descending), but print the output in ascending order ONLY.

// Input Format :
// The first line contains an integer t, the number of test cases, then follows the t test cases as :
//        The first line of the input contains an integer n, representing the number of elements in stack.
//        The second line of the input contains n spaced integers, representing the elements to be inserted in stack.

// Output Format :
// For each testcase, print the sorted stack in ascending order. 

// Example Input : 
// 2
// 5
// 4 3 1 2 5
// 6
// 6 2 1 4 3 2
// Example Output : 
// 1 2 3 4 5
// 1 2 2 3 4 6

#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    // Function to initialize an empty stack
    void createStack(int size) {
        elements.reserve(size);
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Function to push an integer onto the stack
    void push(int value) {
        elements.push_back(value);
    }

    // Function to pop the top element from the stack
    int pop() {
        int top = elements.back();
        elements.pop_back();
        
        return top;
    }

    // Function to print the elements of the stack
    void printStack() const {
        for (int i = 0; i < (int) elements.size(); i++)
        {
            cout << elements[i] << " ";
        }
    }

    // Function to return the top element of the stack
    int top() const {
        return elements.back();
    }

    // Recursive function to insert an element at the correct position in a sorted stack
    void sortedInsert(int value) {
        if (isEmpty() || value >= top())
        {
            push(value);
        }
        else
        {
            int temp = pop();
            
            sortedInsert(value);
            
            push(temp);
        }
    }

    // Recursive function to sort the given stack in ascending order
    void sortStack() {
        if (isEmpty())
        {
            return;
        }
        
        int temp = pop();
        sortStack();
        
        sortedInsert(temp);
    }
};

int main() {
    int t; cin >> t;
    while(t--){
        Stack stack;

        int n; cin >> n;
        stack.createStack(n);
        
        for(int i=0; i<n; i++){
            int k; cin >> k;
            stack.push(k);
        }
    
        // Sorting the stack
        stack.sortStack();
    
        stack.printStack();
        
        cout << endl;
    }
    return 0;
}
