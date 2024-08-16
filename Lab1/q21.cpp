// Given a matrix M, return a array of numbers where the elements of M are arranged in concentric-form.

// Input Format - The first line of input will be n , m denoting the number of rows and columns in the matrix. 
// Next n lines in the input will contain m integers each representing the matrix M.

// Output Format - Print the concentric-form in a single line with spaces after each element i.e n*m elements in a single line. 
// Please refer to example output or the test case for more clarity.

// Example Input - 
// 2 2 
// 1 2
// 3 4

// Example Output - 
// 1 2 4 3 

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class matrix{
    private:
        int n, m;
        vvi arr;
    
    public:
        matrix(int n, int m): n(n), m(m), arr(n, vi(m, 0)){
            
        }
        
        void input()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cin>>arr[i][j];
                }
            }
        }
        
        void solve()
        {
            vi ans;
            
            int top = 0;
            int left = 0;
            int bot = n-1;
            int right = m-1;
            
            while (top <= bot && left <= right)
            {
                for (int i = left; i <= right; i++)
                {
                    ans.emplace_back(arr[top][i]);
                }
                top++;
                
                for (int i = top; i <= bot; i++)
                {
                    ans.emplace_back(arr[i][right]);
                }
                right--;
                
                if (top <= bot)
                {
                    for (int i = right; i >= left; i--)
                    {
                        ans.emplace_back(arr[bot][i]);
                    }
                    bot--;
                }
                
                if (left <= right)
                {
                    for (int i = bot; i >= top; i--)
                    {
                        ans.emplace_back(arr[i][left]);
                    }
                    left++;
                }
            }   
            
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
        }
    
};

int main(void) {
    // Write your code here
    int n, m;
    cin>>n>>m;
    
    if (n == 0 || m == 0)
    {
        cout << 0;
        return 0;
    }
    
    matrix mat(n, m);
    
    mat.input();
    mat.solve();
    

    return 0;
}
