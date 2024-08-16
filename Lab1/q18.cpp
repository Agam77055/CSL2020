// Write the body of the function that takes a matrix as an input, and return a tuple having sums of the upper-triangular and lower triangular matrices.

// Sample Input:
// 3
// 6 5 4
// 1 2 5
// 7 9 7

// Sample Output:
// 29 32

// Explanation:
// Since, for the given input matrix, the upper-triangular matrix is:  
//     [[6, 5, 4],
//      [0, 2, 5],
//      [0, 0, 7]] => Sum = (6 + 5 + 4 + 0 + 2 + 5 + 0 + 0 + 7) = 29
// and, the lower triangular matrix is: 
//     [[6, 0, 0],
//      [1, 2, 0],
//      [7, 9, 7]] => Sum = (6 + 0 + 0 + 1 + 2 + 0 + 7 + 9 + 7) = 32

// Thus, the output 29 32


#include <bits/stdc++.h>  
using namespace std;  

typedef vector<int> vi;
typedef vector<vi> vvi;

class matrix{
    private:
        int n;
        vvi mat;
    
    public:
        matrix(int n): n(n), mat(n, vi(n, 0)){
            
        }
        
        void input()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin>>mat[i][j];
                }
            }
        }
        
        void solve()
        {
            int lsum = 0, rsum = 0;
            
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i >= j)
                    {
                        lsum += mat[i][j];
                    }
                    
                    if (i <= j)
                    {
                        rsum += mat[i][j];
                    }
                }
            }
            
            cout << rsum << " " << lsum;
        }
};

int main() {
   //code
    int n;
    cin>>n;
   
    matrix mat(n);
   
    mat.input();
    mat.solve();
  
}
