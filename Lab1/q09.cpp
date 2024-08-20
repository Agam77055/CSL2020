// Given a matrix M, find another matrix where every (i,j)th element is set to the sum of the elements of M which are below (i,j) and to the right of (i.j). 
// If No element is present in right and left then keep the value of this element is 0. 
// You have to write a function compute_matrix(M), which will take array as matrix M and print array matrix described above . 

// Input Format - The first line of input will be n , m denoting the rows and columns in the matrix. 
// Next n lines in the input will contain m integers each representing the matrix M.

// Output Format - Print the required matrix in the form given in the input, i.e. n rows containing m integers each.

// Example Input - 
// 2  2 
// 1 2
// 2 4
// Example Output - 
// 8 6
// 4 0


#include<bits/stdc++.h>
using namespace std;

#define rows 100
#define cols 100
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;

void compute_matrix(vvi arr, int n, int m){
    // Complete this function
    
    vvi ans(n, vi(m, 0));
    
    FOR(i, n)
    {
        FOR(j, m)
        {
            for (int z = i; z < n; z++)
            {
                if (z > i)
                {
                    FOR(k, m)
                    {
                        ans[i][j] += arr[z][k];
                    }
                }
                else
                {
                    for (int k = j; k < m; k++)
                    {
                        ans[i][j] += arr[z][k];
                    }
                }
            }
            
            ans[i][j] -= arr[i][j];
        }
    }
    
    FOR(i, n)
    {
        FOR(j, m)
        {
            cout << ans[i][j] << " ";
        }
        
        cout << endl;
    }
}

int main(){
    // Feel free to create any helper function if needed.
    // Add your code here.
    int n, m;
    cin>>n>>m;
    
    vvi arr(n, vi(m, 0));
    
    FOR(i, n)
    {
        FOR(j, m)
        {
            cin>>arr[i][j];
        }
    }
    
    compute_matrix(arr, n, m);
}
