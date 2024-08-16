// You are given a matrix M of size n x m and a set of numbers k, row1, col1, row2, col2. 
// You have to return M after adding k to the submatrix starting at (row1, col1) and ending at (row2, col2).

// E.g.: For a matrix 
// M =[
// [1, 2, 3],
// [1, 1, 0],
// [4, -2, -2] ]
// with k = 2, (row1,col1) = (0,0), (row2,col2) = (1,1), the new matrix M' becomes:
// M' = [
// [3, 4, 5],
// [3, 3, 0],
// [4, -2, -2] ]

// Input:
// n
// m
// M[0,0] M[0,1] ... M[0,m-1]
// M[1,0] M[1,1] ... M[1,m-1]
// .
// .
// .
// M[n-1,0] M[n-1,1] ... M[n-1,m-1]
// k
// row1 col1
// row2 col2

// Output:
// M'[1,0] M'[1,1] ... M'[1,m-1]
// .
// .
// .
// M'[n-1,0] M'[n-1,1] ... M'[n-1,m-1]

// (where M' is the updated matrix)

// All variables are within CPP bounds for int data type (even after updating the matrix)

// Note: The output matrix is to be printed with single-space separated columns, and newline character separated rows (including after the last row) 



#include <iostream>
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
    void printMatrix() {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << M[i][j] << " ";
            } 
            
            cout << endl;
        }
        return;
    }
    
    void add_k_matrix(int k, int row1, int col1, int row2, int col2) {
        // Add k to each element in the submatrix defined by (row1, col1) to (row2, col2)
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                M[i][j] += k;
            }
        }
        return;
    }
};


int main(){
    int n = 0, m= 0;
    
    // Input n and m here
    cin>>n>>m;
    
    Matrix mat(n,m);
    
    int k, row1, col1, row2, col2;
    
    // Input M matrix here
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>mat.M[i][j];
        }
    }
    
    // Input k and submatrix boundaries here
    cin>>k>>row1>>col1>>row2>>col2;
    
    // Apply addition to the submatrix
    
    int temp = row1;
    row1 = min(row1, row2);
    row2 = max(temp, row2);
    
    temp = col1;
    col1 = min(col1, col2);
    col2 = max(temp, col2);
    
    mat.add_k_matrix(k, row1, col1, row2, col2);
    mat.printMatrix();
    
    // Print the updated matrix
    return 0;
}
