// Problem:
// Given a linked list and a list of operations to be performed on the list, print the linked list after each operation.
// There are two types of operations, insertion and deletion. Insertion involves inserting the given element at the front of the linked list, 
// and deletion involves removing the element from the front of the linked list. This will demonstrate the Last In First Out (LIFO) operations in a linked list.

// Input Format:
// First line contains an integer n, the initial number of elements in the linked list.
// Second line contains n integers, denoting the initial elements of the linked list.
// Third line contains an integer m, the number of operations to be performed.
// Next m lines contain two integers each, a & b:
// If a == 1, insert b at the front of the linked list.
// If a == 2, b will always be -1; perform deletion from the front of the linked list.

// Output Format:
// Print m lines, showing the linked list after each operation.

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
// 10 5 4 3 2 1 NULL
// 5 4 3 2 1 NULL
// 4 3 2 1 NULL
// 20 4 3 2 1 NULL


#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)

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
           n->next = head;
           head = n;
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
        return;
    }
    
    // point the element to the head of the list
    elem->next = l.head;
    
    // make the new element the head of the list
    l.head = elem;

}

void deletion_operation(LinkedList &l){
    // delete the elem from the front
    
    // if list is empty, return the list as there is nothing to delete
    if (l.head == NULL)
    {
        return;
    }
    
    // store the head element in a temp node
    node* temp = l.head;
    
    // point the head pointer to the next element
    l.head = l.head->next;
    
    // free the head element from the memory;
    delete temp;
    
}

int main(){
    // initialize the linked list 
    LinkedList list;
    
    // take input for linked list
    int n;
    cin>>n;

    // take input for the operations
    FOR(i, n)
    {
        int num;
        cin>>num;
        
        list.insert(num);
    }
    
    // perform operation and after the operation print the list
    
    int m;
    cin>>m;
    
    FOR(i, m)
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
        else
        {
            int num;
            cin>>num;
            
            deletion_operation(list);
            
            list.printLinkedList();
        }
        
    }
    
    return 0;
}
