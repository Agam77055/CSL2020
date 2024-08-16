// Given a matrix M, return the sum of the I path from it. Complete the function isum to implement this functionality.
// Input Format: - First line states the value of N and M, which indicates N*M matrix. (M is odd).
// Followed by N lines each containing M integers. 


// Example:
// Given, matrix :
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// Output : 39
// Explanation : I shape is formed by top row(1+2+3+4+5) + bottom row(1+2+3+4+5) + middle column(3+3+3) = 15 + 15 + 9 = 39


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
    int solve(matrix& mat){
        //write your code here, return the sum in the end.
        int sum = 0;
        
        if (mat.n == 1 && mat.m == 1)
        {
            sum = mat.M[0][0];
            return sum;
        }
        
        for (int i = 0; i < mat.n; i++)
        {
            for (int j = 0; j < mat.m; j++)
            {
                if (i == 0 || i == mat.n - 1)
                {
                    sum += mat.M[i][j];
                }
                else if (j == mat.m / 2)
                {
                    sum += mat.M[i][j];
                }
                
            }
        }
        
        return sum;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // 1. Instantiate a matrix object with the input shape taken.
    // 2. use for loop to set it's elements.
    // 3. Create a solution object and call its member function solve.
    // 4. print the value returned by the member solve.
    int n, m;
    cin>>n>>m;
    
    matrix Mat(n, m);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>Mat.M[i][j];
        }
    }

    solution sol;
    
    cout << sol.solve(Mat);

    return 0;
}
