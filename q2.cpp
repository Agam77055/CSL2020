// You are given a grid of size ‘4 x N’ and boxes of size (1 x 4) and (4 x 1). You have to fill the grid with these boxes. 
// Write a function grid(n) which will take n as an argument and return the total number of ways you can fill the grid using boxes of given size.

// Input format:
// There's a single line input which contains the integer n.
// Constraints: n > 0

// Output format:
// There should be single line output containing the answer integer


// Sample Test Case:
// Input:
// 4
// Output:
// 2

// Explanation: The size of the grid is 4 x 4, and there are only two ways to fill the grid. 
// Either arrange all boxes of size (4 x 1) vertically or arrange boxes of size (1 x 4) horizontally.




#include <iostream>
using namespace std;

int grid(int n){
    // Write your logic here
    int box[n+1] = {0};
    
    if (n < 4)
    {
        return 1;
    }
    
    if (n == 4)
    {
        return 2;
    }
    
    box[0] = 1;
    box[1] = 1;
    box[2] = 1;
    box[3] = 1;
    box[4] = 2;
    
    for (int i = 5; i <= n; i++)
    {
        box[i] = box[i-1] + box[i-4];
    }
    
    return box[n];
    // return the ans for n
}

int main(){
    // There's no need to change this
    int n; cin>>n;
    cout<<grid(n);
}
