// Write a function that takes an integer input n and returns an n×n matrix filled in a spiral order. 
// The matrix should start filling from the top-left corner, proceeding right across the first row, then down the last column, 
// then left across the bottom row, and finally back up the first column. This pattern should continue inward until the entire matrix is filled.

// Example: For n=3
// 1 2 3
// 8 9 4
// 7 6 5


#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiralMatrix(int n) {
    // Your code here
    vector<vector<int>> arr(n, vector<int>(n,0));
    
    int top = 0;
    int bot = n-1;
    int left = 0;
    int right = n-1;
    
    int z = 1;
    while (left <= right || top <= bot)
    {
        for (int i = left; i <= right; i++)
        {
            arr[top][i] = z++;
        }
        top++;
        
        for (int i = top; i <= bot; i++)
        {
            arr[i][right] = z++;
        }
        right--;
        
        if (top <= bot)
        {
            for (int i = right; i >= left; i--)
            {
                arr[bot][i] = z++;
            }
            bot--;
        }
        
        if (left <= right)
        {
            for (int i = bot; i >= top; i--)
            {
                arr[i][left] = z++;
            }
            left++;
        }
    }
    
    return arr;
    
    
}

int main() {
    int n;
    
    // Taking input for the size of the matrix
    cin >> n;
    
    // Function call to generate the spiral matrix
    vector<vector<int>> result = spiralMatrix(n);
    
    // Printing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
