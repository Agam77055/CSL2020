// You are given a stack of N integers such that the leftmost element is on the top and the rightmost element is at the bottom of the stack.
// In one operation, you can either pop an element from the stack or push any popped element into the stack. 
// You need to maximize the top element of the stack after performing exactly K operations. 
// If the stack becomes empty after performing K operations and there is no other way for the stack to be non-empty, print -1.

// Input format:
// The first line of input consists of two space-separated integers N and K.
// The second line of input consists N space-separated integers denoting the elements of the stack. 
// The first element represents the top of the stack and the last element represents the bottom of the stack.

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
    
    Stack(int size)
    {
        v.reserve(size);
    }
    
    void push(ll val){
        v.push_back(val);  
    }
    
    void pop(){
        if (empty()) return;
        v.pop_back();
    }
    
    ll peek(){
        if (empty()) return -1;
        return v.back();
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
    
    Stack st1(n);
    Stack st2(n);
    
    // take input elements and push them in stack
    // remember the leftmost elem should be at the top so you need to push them in reverse order
    
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        
        st1.push(num);
    }
    
    while (!st1.empty())
    {
        st2.push(st1.peek());
        st1.pop();
        
        // cout << st2.peek() << " ";
    }
    
    
    for (int i = 0; i < n; i++)
    {
        if (k > 0)
        {
            if (k % 2 == 0)
            {
                mx = max(mx, st2.peek());
                st2.pop();
                // cout << mx << " ";
            }
            else st2.pop();
            
            k--;
        }
        else
        {
            break;
        }
       
    }
    
    // handle base case
    if (!st2.empty())
    {
        mx = max(mx, st2.peek());
        // cout << st2.peek();
    }
    
    if (mx == -1e9)
    {
        mx = -1;
    }
    
    // write the main solution code


    // OUTPUT
    print(mx);
    return 0;
}
