// Given an expression string, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct 
// in the given expression using a stack. Output 1 if expression is balanced, 0 if not.

// Input : “[()]{}{[()()]()}” 
// Output: 1

// Input : “[()]{}{[()()()}” 
// Output: 0

// Constraints:
// 1 <= 'N' <= 10^3

// Where 'N' is the length of the input string.


#include <bits/stdc++.h>
using namespace std;

class Stack {
    // Add stack implementation here
    private:
        vector<char> v ;
    
    public:
        void push(char c)
        {
            v.push_back(c);
        }
        
        void pop()
        {
            if (isEmpty() == true)
            {
                return;
            }
            
            v.pop_back();
        }
        
        int top()
        {
            return v.back();
        }
        
        bool isEmpty()
        {
            if (v.size() == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

bool isValid(string s) {
    // Add your code here.
    Stack st;
    
    for (char c: s)
    {
        if (c == '{' || c == '(' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.isEmpty() == true)
            {
                return false;
            }
            
            char top = st.top();
            
            // cout << top << " ";
            
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || 
                    (c == ']' && top != '[') )
            {
                return false;
            }
            
            st.pop();
        }
        
    }
    
    return st.isEmpty();
}

int main() {
    // Do not change this.
    string s;

    cin>>s;

    // Check if parentheses are valid and print 1 or 0
    cout << (isValid(s) ? 1 : 0) << std::endl;

    return 0;
}
