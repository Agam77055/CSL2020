// Convert elements of array into 8 bit binary codes using
// example:
// input array : [0, 1, 2, 3, 15, 16, 32, 64, 128]
// output:
// [[0 0 0 0 0 0 0 0]
//  [0 0 0 0 0 0 0 1]
//  [0 0 0 0 0 0 1 0]
//  [0 0 0 0 0 0 1 1]
//  [0 0 0 0 1 1 1 1]
//  [0 0 0 1 0 0 0 0]
//  [0 0 1 0 0 0 0 0]
//  [0 1 0 0 0 0 0 0]
//  [1 0 0 0 0 0 0 0]]

// Input format: First line contains N, the size of array.
// 2nd line contains N integers, the elements of the array.


#include<bits/stdc++.h>
using namespace std;

int main(){
    int size1; cin>>size1;
	vector<int> A(size1);
	for (int i = 0; i < size1; i++) cin>>A[i];
    //write your code here
    
    vector<vector<int>> mat(size1, vector<int>(8, 0));
    
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            mat[i][8 - j - 1] = A[i] % 2;
            A[i] /= 2;
        }
    }
    
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << mat[i][j] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
