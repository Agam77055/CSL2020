// Given a matrix M (r x c) as input and write a complete the function which outputs an array which contains the column wise sum of of the transpose of M. 
// (Do not use any library other than iostream)

// Input format:
// First line contains two integers r and c,      the rows and the columns of the matrix respectively.
// Next r lines contains c integers each,         representing the elements of the row.

// Constraints: 1 <= r,c <= 100  |  -1000 <= matrix elements <= 1000

// Output format:
// There should be single line output with space separated integers:     the sums of each column of the transpose of the matrix

// Sample Test Case:
// Input:
// 2 3 
// 1 2 3 
// 4 5 6 
// Output:
// 6 15

// Explanation:
// Transpose of the matrix is:
// 1 4
// 2 5
// 3 6
// Sum of Cols is: 1+2+3 = 6, 4+5+6 = 15


#include <iostream>
#include <vector>
using namespace std;

// use this matrix
int arr[101][101];

void col_wise_sum_of_transpose(int n,int m){
    // write the logic here
    vector<vector<int>> mat(n, vector<int>(m));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>mat[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        
        for (int j = 0; j < m; j++)
        {
            sum += mat[i][j];
        }
        
        cout << sum << " ";
    }
    
    // print the array
    
    return;
}


int main(){
    // get the rows and columns
    int n, m;
    cin>>n>>m;
    
    // get the matrix
    
    
    // call the function
    
    col_wise_sum_of_transpose(n, m);
    

    return 0;
}
