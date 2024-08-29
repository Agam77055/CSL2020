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
        int top = -1;
        vector<char> v;
    
    public:
        void push(char c)
        {
            top++;
            v.push_back(c);
        }
        
        char pop()
        {
            if (!isEmpty())
            {
                return ' ';
            }
            
            char x = v[top--];
            v.pop_back();
            
            return x;
        }
        
        bool isEmpty()
        {
            return v.empty();
        }
        
};

void infixToPostfix(const char* infix, char* postfix) {
    Stack st;
    
    for (int i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            int x = st.
        }
        
    }
    
}

int main() {
    char infix[100];
    char postfix[100];

    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << postfix << "\n";

    return 0;
}
