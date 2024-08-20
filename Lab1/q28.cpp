// Write a  program(Not function) to find out the difference between the two arrays.
// let's say if you are having two arrays A, B then you have to find out set difference (A-B) as well as (B-A) 

// Input Format: 
// 1. The first line contains an integer N, the size of the arrays.
// 2. The second line contains N space-separated integers for the first array.
// 3. The third line contains N space-separated integers for the second array.

// Output Format: 
// A single line containing the space-separated integers of the set-difference of the two arrays. 

#include<bits/stdc++.h>
using namespace std;

#define FOR(i, size) for(int i = 0; i < size; i++)

int main(){
    int size1; cin>>size1;
	int size2 = size1;
	vector<int> A(size1);
	vector<int> B(size2);
	unordered_set<int> a;
	unordered_set<int> b;

	for (int i = 0; i < size1; i++)
	{
	    cin>>A[i];
	    a.insert(A[i]);
	}
    for (int i = 0; i < size2; i++)
    {
        cin>>B[i];
        b.insert(B[i]);
    }
    
    //write your code here
    
    FOR(i, size1)
    {
        auto it = a.find(B[i]);
        
        if (it != a.end())
        {
            a.erase(it);
        }
    }
    
    FOR(i, size2)
    {
        auto it = b.find(A[i]);
        
        if (it != b.end())
        {
            b.erase(it);
        }
    }
    
    vector<int> A_B;
    vector<int> B_A;
    
    for(auto it: a)
    {
        A_B.emplace_back(it);
    }
    
    for(auto it: b)
    {
        B_A.emplace_back(it);
    }
    
    sort(A_B.begin(), A_B.end());
    sort(B_A.begin(), B_A.end());
    
    for(auto it: A_B)
    {
        cout << it << " ";
    }
    
    cout << endl;
    
    for (auto it: B_A)
    {
        cout << it << " ";
    }
    
    return 0;
}
