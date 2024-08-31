// Design and implement a program to convert an infix expression to its corresponding postfix expression using a stack. The program should support expressions containing operators '+', '-', '*', '/', and parentheses '(' and ')' and provide a mechanism to handle operator precedence and parentheses.
// Example Testcases
// Input:
// A*B+C
// Output:
// AB*C+

// Input:
// A+B*C-D/E
// Output:
// ABC*+DE/-

// Input:
// (A+B)*(C-D)

// Output:
// AB+CD-*

  
#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
        char* arr;
        int top;
    
    public:
        Stack(): top(-1) {
            arr = new char[100];
        }
        
        ~Stack()
        {
            delete[] arr;
        }
        
        void push(char c)
        {
            arr[++top] = c;
        }
        
        char pop(void)
        {
            if (isEmpty())
            {
                throw out_of_range("Stack underflow");
            }
            
            return arr[top--];
        }
    
        char peek() const
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

int precedence(char c)
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    
    return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack op;
    int j = 0;
    
    for (int i = 0; i < (int) strlen(infix); i++)
    {
        char c = infix[i];
        
        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            op.push(c);
        }
        else if (c == ')')
        {
            while (!op.isEmpty() && op.peek() != '(')
            {
                postfix[j++] = op.pop();
            }
            
            op.pop();
        }
        else
        {
            while (!op.isEmpty() && precedence(op.peek()) >= precedence(c))
            {
                postfix[j++] = op.pop();
            }
            
            op.push(c);
        }
        
    }
    
    while (!op.isEmpty())
    {
        postfix[j++] = op.pop();
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];

    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << postfix << "\n";

    return 0;
}
