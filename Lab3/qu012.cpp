// Convert a mathematical expression from prefix notation (Polish notation) to postfix notation (Reverse Polish notation).

// Input
// A single line containing a valid prefix expression with single-letter operands (e.g., A, B, C) and operators +, -, *, /, and ^. The expression is provided as a continuous string.

// Output
// A single line with the equivalent postfix expression.

// Constraints
// The expression length does not exceed 100 characters and is well-formed.

#include <iostream>
#include <string>
#include <cctype>

// Node structure for the stack
struct Node {
    std::string data;
    Node* next;
};

// Stack class using a linked list
class Stack {

};

// Function to convert prefix to postfix
std::string prefixToPostfix(const std::string& prefix) {
    Stack stack;

}

int main() {
    std::string prefix;
    std::cin >> prefix;

    try {
        std::string postfix = prefixToPostfix(prefix);
        std::cout << postfix << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
