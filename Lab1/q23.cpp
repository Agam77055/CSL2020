// Consider a matrix with all elements as zeros. Given n and m are the dimensions of the matrix.  
// Given the array of indices say 'index' and index[i] = [ni, mi].  
// For each pair of indices i.e., index[i] given, increment all the values in row ni first, then increment all the values in column mi by 1. 
// Repeat the procedure for all pairs of indices given.
// Finally, return the number of elements with even values in the matrix.  

// For example: n = 2, m = 3, index = [[0, 1], [1, 1]]. First initialize the matrix to zeros. Then consider [0, 1]. Increment the values along the 0th row. 
// Then, increment the values along the 1st column. The resultant matrix is [[1, 2, 1], [0, 1, 0]]. Now consider the 2nd index [1, 1]. 
// Increment all the values in 1st row, and then increment values in 1st column. The final resultant matrix obtained is [[1, 3, 1], [1, 3, 1]]. 
// So counting the number of even values in the above resultant, it is zero.

// Input:
// n
// m
// index_len
// index[1,1] index[1,1]
// index[2,1] index[2,2]
// .
// .
// .
// index[index_len,1] index[index_len,2]

// Output:
// evenCount

// (where evenCount is the required answer)


#include <iostream>
#include <vector>
using namespace std;

int IndicesIncrementAndEvenCounter(vector<vector<int>>* index, int n, int m, int index_len){
    int evenCount = 0;
    // Write your solving function here
    //increment the rows and columns of the indices and then return the count of even values 
    vector<vector<int>> mat(n, vector<int>(m, 0));
    
    // // vector<int> row(n, 0);
    // // vector<int> col(m, 0);
    
    
    
    for (int z = 0; z < index_len; z++)
    {
        for (int i = 0; i < n; i++)
        {
            mat[i][(*index)[z][1]]++;
        }
        
        for (int i = 0; i < m; i++)
        {
            mat[(*index)[z][0]][i]++;
        }
        
        // row[(*index)[z][1]]++;
        // col[(*index)[z][0]]++;
        
        // mat[(*index)[z][0]][(*index)[z][1]]++;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // int val = row[i] + col[j];
            
            // if (val % 2 == 0)
            // {
            //     evenCount++;
            // }
            
            if (mat[i][j] % 2 == 0)
            {
                evenCount++;
            }
            
            // cout << mat[i][j] << " ";
        }
        
        // cout << endl;
    }
    
    // bool rows[n], cols[m];
    
    // for (int i = 0; i < index_len; i++)
    // {
    //     rows[(*index)[i][0]] ^= true;
    //     cols[(*index)[i][1]] ^= true;
    // }
    
    // int rowsEven = 0, colsEven = 0;
    
    // for (int i = 0; i < n; i++)
    // {
    //     if (rows[i])
    //     {
    //         rowsEven++;
    //     }
    // }
    
    // for (int i = 0; i < m; i++)
    // {
    //     if (cols[i])
    //     {
    //         colsEven++;
    //     }
    // }
    
    // return rowsEven*colsEven + (n-rowsEven)*(m-colsEven);
    
    
    return evenCount;
}


int main(){
    int n, m;
    int index_len;
    cin>>n>>m>>index_len;
    
    if (n <= 0 || m <= 0 || index_len < 0)
    {
        cout << 0;
        return 0;
    }
    
    vector<vector<int>> index(index_len, vector<int>(2, 0));
    
    for (int i = 0; i < index_len; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>index[i][j];
        }
        
        if (index[i][0] >= n || index[i][1] >= m)
        {
            // cout << 0;
            return 0;
        }
    }
    
    // Write your code for taking input (n,m,index_len,index) here:
    
    int evenCount = IndicesIncrementAndEvenCounter(&index, n, m, index_len);
    cout << evenCount;
    return 0;
}
