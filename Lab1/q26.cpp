// Consider a 1xN chess board. Suppose each square can be colored with one of the three colors Red, White or Blue. 
// Then find the number of ways of coloring the n squares so that no two adjacent squares are colored red.

// Input Format: A single integer N.
// Output Format: A single integer

// Sample Input: 1
// Sample Output: 3

#include <bits/stdc++.h>
using namespace std;

int chess(int n){
    // Your code goes here
    if (n == 1) return 3;
    if (n == 2) return 8;
    
    int prev2 = 3;
    int prev1 = 8;
    int current = 0;
    
    for (int i = 3; i <= n; i++)
    {
        current = 2 * (prev1 + prev2);
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

int main(){
    int n; cin>>n;
    
    if (n <= 0)
    {
        cout << 0;
        return 0;
    }
    
    cout<<chess(n);

    return 0;
}
