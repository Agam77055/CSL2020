// The season of Oranges has finally came, and you are a big fan of its Juice. 
// Thus you purchased different packets (n different packets) with different quantities of Oranges. 
// You extracted Juice from all of them and stored them in different jugs (a1,a2,a3.....an) .
// Moreover you are also a fan of Coding , and thus you became curious to know what can be the maximum possible 
// difference between Maximum and Minimum amount of Juice in Jugs, when you can transfer any amount (possible all) of juice from one jug to another, 
// at most k number of times. Assume Jugs have infinite capacity.

// Input Format
// First line contains two integers - n (No of Jugs) and  k (No of Transfers)
// Second line contains n space separated integers denoting quantity of juice in particular jug. 
// Input constraints are - 
// 1 <= k < n < 200000
// 0 <= ai <= 109

// Output Format 
// Return the Maximum Possible Difference between the Maximum and Minimum values in the Jugs after transferring.

// Sample Test Case
// Input - 
// 4 1
// 5 5 5 5
// Output - 
// 10
// Explanation - 
// In one transfer you can , take all the juice from any jug say first and transfer it to second. Thus the amount in jugs becomes - [ 0, 10, 5,  5 ]. 
// Thus the Maximum Possible Difference between Maximum and Minimum values is 10-0 = >10.

#include <bits/stdc++.h>
using namespace std;

#define ll long long int


class Juice{
    private:
        int n,k;
        vector<int> arr;
    public:
        Juice(int n,int k,vector<int>& arr){
            this->n = n;
            this->k = k;
            this->arr = arr;
        }

        // Complete the following function
        long long solve(){ 
            long long ans = 0;
            
            sort(arr.begin(), arr.end());
            
            for (int i = 0; i <= k; i++)
            {
                ans += arr[n-i-1];
            }
            
            return ans;
        }

};


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    Juice JuiceClass(n,k,arr);
    cout<<JuiceClass.solve()<<"\n";
    
    return 0;
}
