// Imagine you're playing a team game with a friend, and both of you are identical in every way. 
// You each have a sword that inflicts a specific amount of damage, K. In front of you lies a row of creatures blocking access to valuable loot. 
// Your goal is to eliminate these creatures to reach the rewards.

// On your turn, you can only attack one creature at a time. You must select the creature with the highest health.
// If there are multiple creatures with the same highest health, you must choose the one with the lowest index, starting from 0. 
// When you attack a creature, if its health is less than or equal to K, it is defeated; otherwise, its health is reduced by K.

// You and your friend will continue attacking until all the creatures are defeated, allowing you to access the loot. 
// Your task is to determine the order in which the creatures are defeated, based on their indices.

// Input Format:
// The first line contains two integers: n (the number of creatures) and K (the damage inflicted by the sword in one attack).
// The second line contains n integers representing the health of each creature, separated by spaces.

// Output Format: 
// A list of indices representing the order in which the creatures are defeated. Each index should be separated by a space.

// Sample Test Case:
// Input:
// 3 2
// 1 2 3
// Output:
// 1 0 2

// Explanation
// Here, n is 3 and k is 2. The health array of bad creatures is [1,2,3]. First, you will attack the 3rd creature. 
// Its health is greater than 2, so it will decrease by 2. The new health array is [1,2,1].
// Next, you will attack the 2nd creature. Its health is equal to 2, so it will be killed in one attack, reducing its health to 0. The health array now is [1,0,1].

// Then, you will attack the 1st creature to kill it. The health array will become [-1,0,1]. 
// After that, you will attack the 3rd creature to kill it as well, resulting in a health array of [-1,0,-1].
// Now, all creatures have been killed. The order in which you killed them is: 2nd, 1st, and 3rd. 
// Therefore, your answer will be [1,0,2], since indexing starts from 0.

#include<bits/stdc++.h>

using namespace std;

# define ll long long


class Solution{
    ll k;
    vector<ll> a; 
public:
    Solution(ll damage, vector<ll> v){
        k = damage;
        a = v;
    }
    // Complete the function.
    vector<ll> solve(){
        vector<ll> ans;
        map<ll, vector<int>> mpp;
        
        for (int i = 0; i < a.size(); i++)
        {
            a[i] %= k;
            mpp[a[i]].push_back(i);
        }
        
        for (auto it: mpp[0])
        {
            ans.push_back(it);
        }
        
        for (int i = k-1; i > 0; i--)
        {
            for (auto it: mpp[i])
            {
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};


// Do not change this starter code
int main(){
    ll n,k;cin>>n>>k;
    
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    Solution S(k,a);

    vector<ll> ans = S.solve();
    for(auto i:ans) cout<<i<<" ";
    return 0;
}
