// Write a program to reverse the string input given using the stack implemented in the previous question.
// Assume the input to contain only lower case characters.

// Example:
// Input:
// psychophysics
// Output:
// scisyhpohcysp 

#include <iostream>
#include <cstring>// For strlen function
using namespace std;

// Function to reverse a string in place
// void reverseString(char* str) {
//     // Type your logic here
//     int n = strlen(str);
//     for (int i = 0; i < n / 2; i++) {
//         std::swap(str[i], str[n - i - 1]);
//     }
// }

class Stack{
    private:
        char v[1000];
        int top = -1;
    
    public:
        void push(char c)
        {
            top++;
            v[top] = c;
        }
        
        void pop()
        {
            if (!isEmpty())
            {
                return;
            }
            
            v[top] = '\0';
            top--;
        }
        
        bool isEmpty()
        {
            if (top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        void printReverse()
        {
            for (int i = 0; i <= top; i++)
            {
                cout << v[top - i];
            }
            
            cout << endl;
        }
};

int main() {
    char input[100];
    cin >> input;
    
    // reverseString(input);
    
    Stack st;
    
    for (int i = 0; i < strlen(input); i++)
    {
        st.push(input[i]);
    }
    
    st.printReverse();
    
    // cout << input << std::endl;
    return 0;
}
