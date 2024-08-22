// A Linked List is a linear data structure where elements, called nodes, are stored in a sequence. 
// Each node contains a value and a reference (or pointer) to the next node in the sequence, 
// allowing for dynamic memory allocation and efficient insertion or deletion of elements. The starting node of a linked list is called its head. 

// Problem:
// Given heads of two linked lists, concatenate the linked lists by connecting both of them.
// Connect the head of linked list 2 with the last node of linked list 1, i.e. concatenate the linked lists to create one big list. 

// Input Format:
// First line contains two integers n and m, the lengths of the two linked lists.
// Second line contains n integers, values for linked list 1
// Third line contains m integers, values for linked list 2

// Output Format:
// Print the resulting big linked list


// Sample Test Case:
// Input:
// 2 3
// 1 2
// 3 4 5

// Output:
// 1 2 3 4 5 NULL

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)

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

node* concatenate(node* head1,node* head2){
    // Implement the required logic
    if (head1 == NULL)
    {
        return head2;
    }
    
    node* x = head1;
    
    while (x->next != NULL)
    {
        x = x->next;
    }
    
    x->next = head2;
    
    return head1;
}


int main(){
    // make instances for the two linked lists
    LinkedList l1;
    LinkedList l2;
    
    // take input for the two linked lists
    int n, m;
    cin>>n>>m;

    FOR(i, n)
    {
        int num;
        cin>>num;
        
        l1.insert(num);
    }
    
    FOR(i, m)
    {
        int num;
        cin>>num;
        
        l2.insert(num);
    }
    
    // call the concatenate function
    l1.head = concatenate(l1.head, l2.head);
    
    // print the linked list using printLinkedList function
    l1.printLinkedList();
    // l2.printLinkedList();
    
    return 0;
}
