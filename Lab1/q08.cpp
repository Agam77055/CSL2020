// Find the number of distinct elements occurring in the intersection of two sorted arrays of size n and m. 
// Example: a = [1,2,3,4,5,6,7,8,9] b = [4,5,6,7,8,9,4,5,6] have [4,5,6,7,8,9] as common. So the output will be 6. 

// Input Format: - First line states the value of N and M. Followed by 2 lines with n and m elements respectively.

// Example:
// Input 
// 3 2
// 4 4 4
// 1 0 4
// Output 
// 1

// Explanation : 
// Intersection array = [4], Hence size = 1

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

#define FOR(i, size) for(int i = 0; i < size; i++)

class solution{
public:
    int solve(vi& A, vi& B){
        // given 2 input parameters : a, b of type vector<int>
        
        int n = A.size(), m = B.size();
        // Return one integer : Size of the intersection array.
        // Complete this function now.
        
        set<int> a, b;
        
        unordered_map<int, int> mpp;
        
        FOR(i, n)
        {
            a.insert(A[i]);
        }
        
        for (auto it: a)
        {
            // cout << it << " ";
            mpp[it]++;
        }
        
        FOR(i, m)
        {
            b.insert(B[i]);
        }
        
        for (auto it: b)
        {
            mpp[it]++;
        }
        
        int count = 0;
        
        for (auto it: mpp)
        {
            if (it.second > 1)
            {
                count++;
            }
        }
        
        return count;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    // Write your code here
    
    // 1. Take input sizes n and m
    // 2. Instantiate 2 vector<int> objects a and b with the given sizes.
    //    hint : constructor function for class vector<int> takes 2 parameters - size and initial value.
    // 3. Use for loop to fill their values.
    
    // 4. Create a solution object and call it's member solve with the parameters.
    // 5. Display the returned value.
    
    int n, m;
    cin>>n>>m;
    
    vi a(n), b(m);
    
    FOR(i, n)
    {
        cin>>a[i];
    }
    
    FOR(i, m)
    {
        cin>>b[i];
    }
    
    solution sol;
    
    cout << sol.solve(a, b);
    
    return 0;
}
