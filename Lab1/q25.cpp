// Write a program to:
// 1. First take the input a number n and m. Next take input of an n x m matrix.
// 2. Next take a number row as input. Print the average of that row. (row: 0,1,2..)
// 3. Next take a number column as input. Print the average of that column. (col: 0,1,2..)
// [Print averages upto 2 decimal places]

// Sample Input #1:
// 3
// 3
// 4 5 6
// 9 0 7
// 7 2 1
// 1
// 2

// Sample Output #1:
// 5.33 4.67

// Explanation: 
// (9 + 0 + 7)/3 = 5.33
// (6 + 7 + 1)/3 = 4.67

// (Matrix sizes and values are CPP integers)


#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Matrix{
    private:
    
    public:
    int n, m;
    vector<vector<int>> M;
    
    Matrix(int rowsize, int colsize){
        n = rowsize;
        m = colsize;
        M = vector<vector<int>>(n, vector<int>(m, 0));
    }

    void print_averages(int row, int col){
    // Complete the function here
        float rsum = 0;
        float csum = 0;
        
        for (int i = 0; i < n; i++)
        {
            rsum += M[i][col];
        }
        
        rsum /= n;
        
        for (int i = 0; i < m; i++)
        {
            csum += M[row][i];
        }
        
        csum /= m;
        
        cout << fixed << setprecision(2) << csum << " " << fixed << setprecision(2) << rsum;
        
        return;
    }
};


int main(){
    int n, m;
    
    // Input n and m here
    cin>>n>>m;
    
    Matrix mat(n,m);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>mat.M[i][j];
        }
    }
    
    int row, col;
    // Input matrix and row and col here
    cin>>row>>col;
    
    mat.print_averages(row, col);
    
    return 0;
}
