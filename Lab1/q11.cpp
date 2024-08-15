// Write a program that takes an integer n and an nxn matrix as input, and outputs the lower triangular matrix of the given matrix.

// Note: A lower triangular matrix is a matrix where all the elements including the main diagonal are zero.

// Input format
// 1. The first line of input contains an integer n, representing the size of the matrix.
// 2. The next n lines contain n integers each, representing the elements of the matrix

// Output format
// Print the lower triangular matrix.

// Example Input
// 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output
// 0 0 0
// 4 0 0
// 7 8 0


#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class SquareMatrix {
private:
    int n;
    vvi mat;    

public:
    // Constructor to initialize the matrix size
    SquareMatrix(int size) : n(size), mat(n, vector<int>(n)){
        // TODO: Initialize the matrix
    }

    // Method to input matrix elements
    void inputMatrix() {
        // TODO: Implement input logic
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>mat[i][j];
            }
        }
        
    }

    // Method to print the lower triangular matrix
    void printLowerTriangularMatrix() const {
        // TODO: Implement the logic to print the lower triangular matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > j)
                {
                    cout << mat[i][j] << " ";
                }
                else
                {
                    cout << 0 << " ";    
                }
            }
            
            cout << endl;
        }
        
        return;
    }
};

int main() {
    int n;
    cin >> n;

    // TODO: Create a SquareMatrix object
    SquareMatrix Mat(n);

    // TODO: Input matrix elements
    Mat.inputMatrix();
    
    // TODO: Print the lower triangular matrix
    Mat.printLowerTriangularMatrix();

    return 0;
}
