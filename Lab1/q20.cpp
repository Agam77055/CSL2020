// Given a matrix, output 0 if it is a zero matrix (matrix will all zeros), Output 1 if it is a ones matrix(matrix will all ones),
// Output 2 if it is an identity matrix (square matrix where diagonal are ones, rest are zeros), Output -1 otherwise.

// Input format:
// N M (Dimensions of the matrix)
// N lines containing M integers each.

// For example:
// 5 5
// 1 0 0 0 0
// 0 1 0 0 0
// 0 0 1 0 0
// 0 0 0 1 0
// 0 0 0 0 1

// Output 
// 2

#include <iostream>  
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class matrix{
    private:
        int n, m;
        vvi mat;
    
    public: 
        matrix(int n, int m): n(n), m(m), mat(n, vi(m, 0)){
            
        }
        
        void input()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cin>>mat[i][j];
                }
            }
        }
        
        void solve()
        {
            int identity = 0;
            int zero = 0;
            int ones = 0;
            
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i == j)
                    {
                        if (mat[i][j] == 1)
                        {
                            identity++;
                            ones++;
                        }
                        else if(mat[i][j] == 0)
                        {
                            zero++;
                        }
                    }
                    else
                    {
                        if (mat[i][j] == 1)
                        {
                            ones++;
                        }
                        else if(mat[i][j] == 0)
                        {
                            zero++;
                        }
                    }
                    
                }
            }
            
            if (identity == n && n == m)
            {
                cout << 2;
                return;
            }
            else if (zero == n*m)
            {
                cout << 0;
                return;
            }
            else if (ones == n*m)
            {
                cout << 1;
                return;
            }
            else
            {
                cout << -1;
                return;
            }
        }
        
};
        
int main() {
   //code
   int n, m;
   cin>>n>>m;
   
   matrix mat(n, m);
   
   mat.input();
   mat.solve();
}
