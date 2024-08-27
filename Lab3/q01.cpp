// Write a program to perform the basic operations of a stack such as push(), pop(), peek(), isFull(), isEmpty(). 
// Assume stack is of size 100 integers. The program should take input of a given n number of integers and push them 
// into the stack and then perform the operations in the order mentioned below.

// Input Format:
// 	N 1, 2, 3, ..n integers
// Output Format:
// 	Output of peek(), printWholeStack(), pop(), isFull(), and isEmpty() in a new line:
// Example:
// 	Input : 5 15 123 62 10 44
// 	Output: 
// 		44
// 		44 10 62 123 15 5
// 		44
// 		0 // isFull() returns 1 if full, 0 otherwise
// 		0 // isEmpty() returns 1 if empty, 0 otherwise

#include <bits/stdc++.h>

using namespace std;

#define MX_SIZE 1000

class Stack{
    int top = -1;
    int v[MX_SIZE];

public:
    
    /* Check if the stack is empty */
    int isEmpty(){
    // ADD YOUR CODE
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    /* Check if the stack is full */
    int isFull(){
    //ADD YOUR CODE
        if (top == MX_SIZE-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    /* Function to return the topmost element in the stack */
    int peek(){
    //ADD YOUR CODE
        if (isEmpty() == 1)
        {
            return -1;
        }
        
        return v[top];
    }

    /* Function to delete from the stack */
    int pop(){
    //ADD YOUR CODE
        if (isEmpty() == 1)
        {
            return -1;
        }
        
        int x = top;
        top--;
        return v[x];
    }

    /* Function to insert into the stack */
    void push(int data){
    //ADD YOUR CODE
        if (isFull() == 1)
        {
            return;
        }
        
        top++;
        v[top] = data;
        
    }

    void printWholeStack(){
        for(int i=top;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

};

/* Main function */
int main(){
   
   int n,x,i;
   cin>>n;
   Stack s;
   for(i=0;i<n;i++){
        cin>>x;
        s.push(x);
   }
   x=s.peek();
   cout<<x<<endl;
   s.printWholeStack();
   x=s.pop();
   cout<<x<<endl;
   cout<<s.isFull()<<endl;
   cout<<s.isEmpty()<<endl;
   return 0;
}
