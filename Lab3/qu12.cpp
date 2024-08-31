// Convert a mathematical expression from prefix notation (Polish notation) to postfix notation (Reverse Polish notation).

// Input
// A single line containing a valid prefix expression with single-letter operands (e.g., A, B, C) and operators +, -, *, /, and ^. 
// The expression is provided as a continuous string.

// Output
// A single line with the equivalent postfix expression.

// Constraints
// The expression length does not exceed 100 characters and is well-formed.


#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>

using namespace std;

// Node structure for the stack
struct Node {
    string data;
    Node* next;
};

// Stack class using a linked list
class Stack {
    private:
        string arr[1000];
        int top;
    
    public:
        Stack(): top(-1) {}
        
        void push(string c)
        {
            arr[++top] = c;
        }
        
        void pop()
        {
            if (isEmpty())
            {
                throw out_of_range("Stack Underflow");
            }
            
            top--;
        }
        
        string peek() const
        {
            if (isEmpty())
            {
                throw out_of_range("Stack empty");
            }
            
            return arr[top];
        }
        
        bool isEmpty() const
        {
            return top == -1;
        }
};

// Function to convert prefix to postfix
string prefixToPostfix(const string& prefix) {
    Stack stack;
    
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        char c = prefix[i];
        
        if (isalnum(c))
        {
            stack.push(string(1, c));
        }
        else
        {
            string operand1 = stack.peek();
            stack.pop();
            string operand2 = stack.peek();
            stack.pop();
            
            string postfixExpr = operand1 + operand2 + c;
            stack.push(postfixExpr);
        }
    }
    
    return stack.peek();
}

int main() {
    string prefix;
    cin >> prefix;

    try {
        string postfix = prefixToPostfix(prefix);
        cout << postfix << std::endl;
    } catch (const std::exception& e) {
        cerr << e.what() << std::endl;
    }

    return 0;
}
