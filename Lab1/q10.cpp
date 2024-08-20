// Complete the function printNewMatrix to remove all the all zero rows and columns from the matrix (assume it to be square matrix of shape nxn) 
// and display the resulting matrix from the function itself. You just have to print the new matrix, hence the return type of the function is void.

// Input format : 
// First line contains n.
// Next n lines contain n space-separated integers each, representing the matrix.

// Sample Input:
// 4
// 1 1 0 1
// 0 0 0 0
// 1 1 0 1
// 0 1 0 1

// Sample Output: 
// 1 1 1
// 1 1 1
// 0 1 1

// Explanation:
// Second row and third column are removed

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class matrix{
public:
    int n,m;
    vvi M;
    matrix(int shape0, int shape1){
        n = shape0;
        m = shape1;
        M = vvi(n,vi(m,0));
    }
    void displayMatrix(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout << M[i][j] << ' ';
            cout << '\n';
        }
    }
};

class solution{
public:
    void solve(matrix& mat){
        // write your code here, print your answer here itself.
        
        // Hint : First compute shape of the resulting matrix.
        // Instantiate a new matrix object with this computed shape.
        // Fill the new matrix.
        // Call the displayMatrix member of the new matrix.
        
        // for (int i = 0; i < mat.n; i++)
        // {
        //     int count = 0;
            
        //     for (int j = 0; j < mat.m; j++)
        //     {
        //         if (mat.M[i][j] == 0)
        //         {
        //             count++;
        //         }
        //     }
            
        //     if (count == mat.m)
        //     {
        //         mat.m--;
        //         continue;
        //     }
            
        //     for (int j = )
        // }
        
        // for (int i = 0; i < mat.m; i++)
        // {
        //     int count = 0;
            
        //     for (int j = 0; j < mat.n; j++)
        //     {
        //         if (mat.M[j][i] == 0)
        //         {
        //             count++;
        //         }
        //     }
            
        //     if (count == mat.n)
        //     {
        //         for (int j = 0; j < mat.n; j++)
        //         {
        //             mat.M[j][i].erase(mat.M[j][i].begin() + i);
        //             mat.m--;
        //         }
            // }
            
        
            unordered_map<int, int> mpp1;
            unordered_map<int, int> mpp2;
            
            for (int i = 0; i < mat.n; i++)
            {
                int count = 0;
                
                for (int j = 0; j < mat.m; j++)
                {
                    if (mat.M[i][j] == 0)
                    {
                        count++;
                    }
                }
                
                if (count == mat.m)
                {
                    continue;
                }
                
                mpp1[i]++;
            }
            
            
            for (int i = 0; i < mat.m; i++)
            {
                int count = 0;
                
                for (int j = 0; j < mat.n; j++)
                {
                    if (mat.M[j][i] == 0)
                    {
                        count++;
                    }
                }
                
                if (count == mat.n)
                {
                    continue;
                }
                
                mpp2[i]++;
            }
            
            for (int i = 0; i < mat.n; i++)
            {

                for (int j = 0; j < mat.m; j++)
                {
                    if (mpp1[i] == 1 && mpp2[j] == 1)
                    {
                        cout << mat.M[i][j] << " ";
                    }
                }
                
                if (mpp1[i] == 1)
                {
                    cout << endl;
                }
            }
            
            
    }
        
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // 1. Instantiate a matrix object with the input shape taken
    // 2. use for loop to set it's elements
    // 3. Create a solution object and call its member function solve
    int n;
    cin>>n;
    
    matrix mat(n, n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>mat.M[i][j];
        }
    }
    
    solution sol;
    sol.solve(mat);
    
    return 0;
}
