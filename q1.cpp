// You are given a matrix of size n x n, which is to be the argument for the function along with the matrix. 
// You are expected to print the sum of the left diagonal and right diagonal of the matrix.

// Input:
// 1. The first line contain an integer n greater than 1 and less than 100, representing the size of the matrix.
// 2. The next n lines contain n integers each, representing the elements of the matrix.

// Output:
// Print a single integer which is the sum of left diagonal and right diagonal elements.

// Example input
// 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 30

// Explanation
// left diagonal: 1 + 5 + 9 = 15
// right diagonal: 3 + 5 + 7 = 15
// total sum = 15 + 15 = 30


#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
    int n;
    vector<vector<int>> arr;

public:
    // Constructor to initialize the matrix size
    SquareMatrix(int size) : n(size), arr(n, vector<int>(n)) {
        // TODO: Initialize matrix storage
    }

    // Method to input matrix elements
    void inputMatrix() {
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>arr[i][j];
            }
        }
        // TODO: Implement input logic
    }

    // Method to calculate the sum of both diagonals
    int calculateDiagonalSum() const {
        // TODO: Implement diagonal sum calculation
        int sum = 0;
        
        if (n == 1)
        {
            return arr[0][0];
        }
        
        for (int i = 0; i < n; i++)
        {
            sum += arr[i][i];
            sum += arr[i][n-i-1];

        }
        
        return sum; // Placeholder return value
    }

    // Additional methods (if any) can be added here
};

int main() {
    int n;
    cin >> n;

    // TODO: Create a SquareMatrix object
    SquareMatrix sm(n);

    // TODO: Input matrix elements
    sm.inputMatrix();

    // TODO: Calculate and print the diagonal sum
    cout<<sm.calculateDiagonalSum();

    return 0;
}
