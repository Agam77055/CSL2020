// A Linked List is a linear data structure where elements, called nodes, are stored in a sequence. 
// Each node contains a value and a reference (or pointer) to the next node in the sequence, 
// allowing for dynamic memory allocation and efficient insertion or deletion of elements. The starting node of a linked list is called its head. 

// Problem:
// Given a linked list and a list of operations to be performed on the list, print the linked list after each operation. 
// There are two types of operations, insertion and deletion. 
// Insertion involves inserting the given element at the end of the linked list and deletion involves removing the element from the front of the linked list. 
// Which will demonstrate the First In First Out (FIFO) operations in a linked list.

// Input Format:
// First line contains an integers n, the initial number of elements in the linked list.
// Second line contains n integers, denoting the initial elements of linked list.
// Third line contains an integer m.
// Next m lines contain two integers each, a & b. 
//                                       --- if a==1, insert b. 
//                                       --- if a==2, b will be always -1, perform deletion.

// Output Format:
// Print m lines, the linked list after each operation.


// Sample Test Case:
// Input:
// 5
// 1 2 3 4 5
// 4
// 1 10
// 2 -1
// 2 -1
// 1 20

// Output:
// 1 2 3 4 5 10 NULL
// 2 3 4 5 10 NULL
// 3 4 5 10 NULL
// 3 4 5 10 20 NULL

#include <bits/stdc++.h>
using namespace std;

#define repeat(i,s,e) for(long long i=s;i<e;i++)

class node{
    public:
    int val;
    node* next;
    node(int v=0,node* nxt=NULL){
        val = v;
        next = nxt;
    }
};

class LinkedList{
    public:
    node* head;
    LinkedList(node* h=NULL){
        head = h;
    }
    void insert(int val){
        // complete this insert function
        node* n = new node(val);
        
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node* x = head;
            
            while (x->next != NULL)
            {
                x = x->next;
            }
            
            x->next = n;
        }
    }

    void printLinkedList(){
        // don't alter this printing function
        if (head==NULL){
            cout<<"EMPTY\n";
            return;
        }
        node* curr = head;
        while(curr){
            cout<<curr->val<<' ';
            curr = curr->next;
        }
        cout<<"NULL\n";
    }
};

void insertion_operation(LinkedList &l,node* elem){
    // insert the new elem at the back
    if (l.head == NULL)
    {
        l.head = elem;
    }
    else
    {
        node* x = l.head;
        
        while (x->next != NULL)
        {
            x = x->next;
        }
        
        x->next = elem;
    }
    
}

void deletion_operation(LinkedList &l){
    // delete the elem from the front
    
    // if list is empty, then return nothing
    if (l.head == NULL) return;
    
    // to remove the first element, store the first initial head into a temp and shift the head one space forward;
    
    node* temp = l.head;
    l.head = l.head->next;
    
    // free the temp node
    delete temp;
    
}

int main(){
    // initialize the linked list 
    LinkedList list;
    
    // take input for linked list
    int n;
    cin>>n;
    
    repeat(i, 0, n)
    {
        int num;
        cin>>num;
        
        list.insert(num);
    }

    // take input for the operations
    int m;
    cin>>m;
    
    repeat(i, 0, m)
    {
        int x;
        cin>>x;
        
        if (x == 1)
        {
            int num;
            cin>>num;
            
            node* n = new node(num);
            
            insertion_operation(list, n);
            
            list.printLinkedList();
        }
        else if (x == 2)
        {
            int num;
            cin>>num;
            
            deletion_operation(list);
            
            list.printLinkedList();
        }
    }
    
    // perform operation and after the operation print the list
    
    return 0;
}
