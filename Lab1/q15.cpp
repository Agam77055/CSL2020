// You need to replace each element of the given array by the sum of the element to its right if the element is rightmost, 
// you need to replace that element by zero.  You have to return the replaced array.

// Input:  Array = [[1, 2, 3, 4],
//                 [1, 2, 3, 4],
//                 [1, 2, 3, 4],
//                 [1, 2, 3, 4]])

// Output: Array after interchange =   [[9, 7, 4, 0],
//        						[9, 7, 4, 0],
//        						[9, 7, 4, 0],
//        						[9, 7, 4, 0]])

#include <bits/stdc++.h>  
using namespace std;  

typedef vector<int> vi;
typedef vector<vi> vvi;

#define FOR(i, n) for (int i = 0; i < n; i++)

// class matrix{
//     private:
//         int n, m;
//         vvi arr;
    
//     public:
//         matrix(int n, int m): n(n), m(m), arr(n, vi(n)){
            
//         }
        
//         void input()
//         {
//             FOR(i, n)
//             {
//                 FOR(j, m)
//                 {
//                     cin>>arr[i][j];
//                 }
//             }
//         }
        
//         void solve()
//         {
//             FOR(i, n)
//             {
//                 FOR(j, m)
//                 {
//                     arr[i][j] = 0;
//                     for(int z = j + 1; z < m; z++)
//                     {
//                         arr[i][j] += arr[i][z];
//                     }
//                 }
//             }
            
//             FOR(i, n)
//             {
//                 FOR(j, m)
//                 {
//                     cout << arr[i][j] << " ";
//                 }
                
//                 cout << endl;
//             }
            
//         }
// };

int main() {
    int n, m;
    cin>>n>>m;
   
    // if (n == 0 || m == 0)
    // {
    //     cout << 0;
    //     return 0;
    // }
    
    
    vvi arr(n, vi(m, 0));
    
    FOR(i, n)
    {
        FOR(j, m)
        {
            cin>>arr[i][j];
        }
    }
    
    FOR(i, n)
    {
        FOR(j, m)
        {
            arr[i][j] = 0;
            
            for (int z = j + 1; z < m; z++)
            {
                arr[i][j] += arr[i][z];    
            }
            
            cout << arr[i][j] << " ";
        }
        
        cout << endl;
    }
    
    // matrix Mat(n, m);
   
    // Mat.input();
   
    // Mat.solve();
    
    
}
