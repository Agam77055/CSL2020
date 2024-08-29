// You are given a stack of N integers such that the leftmost element is on the top and the rightmost element is at the bottom of the stack.
// In one operation, you can either pop an element from the stack or push any popped element into the stack. You need to maximize the top element of the stack after performing exactly K operations. If the stack becomes empty after performing K operations and there is no other way for the stack to be non-empty, print -1.

// Input format:
// The first line of input consists of two space-separated integers N and K.
// The second line of input consists N space-separated integers denoting the elements of the stack. The first element represents the top of the stack and the last element represents the bottom of the stack.
// Output format :
// Print the maximum possible top element of the stack after performing exactly K operations.

// Sample test case:
// Input:
// 6 4
// 1 2 4 3 3 5
// Output : 4

#include <bits/stdc++.h>
using namespace std;

#define elif else if
#define print(s) cout<<(s)<<endl
#define ll long long

class Stack{
    // complete the methods and define the required variables 
public:
    vector<ll> v;
    
    void push(ll val){
        v.push_back(val);  
    }
    
    void pop(){
        if (empty()) return;
        v.erase(v.begin());
    }
    
    ll top(){
        return v.front();
    }
    
    ll size(){
        return v.size();
    }
    
    bool empty(){
        return v.empty();
    }
};

int main(){
    // Answer Variable
    ll mx = -1e9;

    
    // take n and k as input
    int n, k;
    cin>>n>>k;
    
    Stack st;
    
    // take input elements and push them in stack
    // remember the leftmost elem should be at the top so you need to push them in reverse order
    
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        
        st.push(num);
    }
    
    for (int i = 0; i < k; i++)
    {
        ll num = st.top();
        st.pop();
        
        if (i == k-1)
        {
            st.v.insert(st.v.begin(), mx);
            break;
        }
        
        if (mx < num)
        {
            mx = num;
        }
        
        // cout << st.top() << " ";
    }
    
    // handle base cases
    
    if (st.empty())
        {
            cout << -1 << endl;
            return 0;
        }

    // write the main solution code


    // OUTPUT
    print(mx);
    return 0;
}
