// Given an array of integers arr, find the sum of minimums of all possible contiguous subarrays of arr. Since the answer may be large, 
// return the answer modulo 10^9 + 7.

// Example: arr = [3,1,2,4]
// Answer: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.

// Example 2 : arr = [11,81,94,43,3]
// Answer: 444

// Input format:
// 1st line contains integer n, size off arr
// next line contains n integers, representing elements of arr.

// Output format:
// a single integer (the sum) mod 10^9+7

// Complete the class definition of Stack data Structure and the function to compute the sum of all minima.

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

class Stack{
    int top;
    vector<int> v;
    int maxSize;

public:

    Stack(int size){
        v = vector<int>(size,0);
        maxSize = size;
        top = -1;
    }

    bool isEmpty(){
        if (top == -1) return true;
        else return false;
        // single boolean expression : when is the stack empty? //
    }

    bool isFull(){
        if (top == maxSize-1) return true;
        else return false;
        // single boolean expression : when is the stack full? //
    }

    int peek(){
        // return the element at the top
        return v[top];
    }

    int pop(){
        if(isEmpty()) cerr << "Popping from empty stack";
        // remove the top element and return it
        int num = v[top];
        v[top] = 0;
        top--;

        return num;
    }

    void push(int x){
        if(isFull()) cerr << "Pushing into a full stack";
        v[++top] = x;
    }

    void printWholeStack(){
        for(int i=top;i>=0;i--) cout << v[i] <<" ";
        cout<<'\n';
    }

};

ll sum_minOfSubArrays(vector<ll>& v){
    int n = v.size();
    ll sum = 0;

    Stack st(n);

    vector<int> rightMinima(n, 0);
    vector<int> leftMinima(n, 0);

    for (int i = 0; i < n; i++)
    {
        while (st.isEmpty() == false && v[st.peek()] >= v[i])
        {
            st.pop();
        }

        if (st.isEmpty() == true)
        {
            leftMinima[i] = i + 1;
        }
        else
        {
            leftMinima[i] = i - st.peek();
        }

        st.push(i);
    }

    while(st.isEmpty() != true)
    {
        st.pop();
    }

    for (int i = n-1; i >= 0; i--)
    {
        while (st.isEmpty() == false && v[st.peek()] > v[i])
        {
            st.pop();
        }

        if (st.isEmpty() == true)
        {
            rightMinima[i] = n - i;
        }
        else
        {
            rightMinima[i] = st.peek() - i;
        }

        st.push(i);
    }


    for (int i = 0; i < n; i++)
    {
        sum = (sum + v[i] * leftMinima[i] * rightMinima[i]) % mod ;
    }

    return sum;

    // Complete the function now

}

int main() {

    int n; cin >> n;
    vector<ll> v(n,0); for(int i=0;i<n;i++) cin >> v[i];

    cout << sum_minOfSubArrays(v) << endl;

    return 0;
}
