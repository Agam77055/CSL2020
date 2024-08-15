// Given a array of numbers, convert every number to it’s binary and store it as a matrix where each row holds a 32 bit binary. 
// So a array of n numbers will generate a nx32 sized matrix. Now return the count of rows which has at least 5 1s.

// Input Format: 
// 1. The first line contains an integer N, the size of the arrays.
// 2. The second line contains N space-separated integers for the first array.

// Output Format: A single Integer

// Sample Input: 
// 5
// 63 62 61 89 90
// Sample Output:
// 3

// Reason:
// give_max_ones([63,62,61,89,90]) returns 3
// Matrix becomes ;
// 00000000000000000000000000111111
// 00000000000000000000000000111110
// 00000000000000000000000000111101
// 00000000000000000000000001011001
// 00000000000000000000000001011010


#include<bits/stdc++.h>

using namespace std;


class Solution{
private:
    int n;
    vector<int> vec;
public:
    
    Solution(int size,vector<int> a)
    {
        n=size;
        vec=a;
    }

    int give_ones()
    {
        int cnt = 0;
        
        for (int i = 0; i < vec.size(); i++)
        {
            int count = 0;
            
            while(vec[i] > 0)
            {
                if (vec[i] % 2 == 1)
                {
                    count++;
                }
                
                vec[i] /= 2;
            }
            
            
            if (count >= 5)
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    Solution s(n,a);
    cout<<s.give_ones();

    return 0;
}
