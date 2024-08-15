// Write a program that generates an nxn matrix filled with concentric layers of characters. 
// The matrix is filled starting from a given character, with each concentric layer using the next character in the alphabet.

// Description
// Given a size n and a starting character c, create an nxn matrix where each concentric layer is filled with increasing characters starting from c. 
// The outermost layer uses the starting character c, the next layer uses the character c+1 and so on. Characters should wrap around from z to a if necessary.

// Input format:
// 1. The first line of input contains an integer n, representing the size of the matrix.
// 2. The second line of input contains a single character c, representing the starting character.

// Output format:
// Print the nxn matrix where each layer is filled with the appropriate character

// Constraints
// n lies between 1 to 20
// c is a lowercase English character from a to z

// Example:
// Input:
// 5
// b

// Output:
// bbbbb
// bcccb
// bcdcb
// bcccb
// bbbbb


#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> vi;
typedef vector<vi> vvi;

class CharacterMatrix {
private:
    int n;
    char startChar;
    vvi mat;

public:
    // Constructor to initialize the matrix size and starting character
    CharacterMatrix(int size, char ch) : n(size), startChar(ch), mat(n, vector<char>(n, 0)) {
        // TODO: Initialize the matrix storage
    }

    // Method to generate the concentric character matrix
    void generateMatrix() {
        // TODO: Implement the logic to generate the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int top = i;
                int left = j; 
                int bot = n - i - 1;
                int right = n - j - 1;
                
                mat[i][j] = startChar + min(min(top, bot), min(left, right));
                
                if (mat[i][j] > 122)
                {
                    mat[i][j] -= 26;
                }
            }
        }
        
    }

    // Method to print the generated matrix
    void printMatrix() const {
        // TODO: Implement the logic to print the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j];
            }
            
            cout << endl;
        }
    }
};

int main() {
    int n;
    char startChar;

    // Read the size of the matrix
    cin >> n;
    // Read the starting character
    cin >> startChar;

    // TODO: Create a CharacterMatrix object
    CharacterMatrix cm(n, startChar);

    // TODO: Generate and print the character matrix
    cm.generateMatrix();
    cm.printMatrix();

    return 0;
}
