// A Linked List is a linear data structure where elements, called nodes, are stored in a sequence. 
// Each node contains a value and a reference (or pointer) to the next node in the sequence, 
// allowing for dynamic memory allocation and efficient insertion or deletion of elements. The starting node of a linked list is called its head. 

// Problem:
// Given heads of two linked lists, concatenate the linked lists such that the concatenated list is sorted. 
// (You can assume that the original lists are sorted already)

// Input Format:
// First line contains two integers n and m, the lengths of the two linked lists. 0 <= n,m <= 100
// Second line contains n integers, values for linked list 1. This line will not be present if n=0
// Third line contains m integers, values for linked list 2. This line will not be present if m=0

// Output Format:
// Print the resulting big linked list.


// Sample Test Case:
// Input:
// 2 3
// 1 2
// 1 2 5

// Output:
// 1 1 2 2 5 NULL


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
        
        // creating node pointer to store the value
        node* n = new node(val);
        
        // checking if head pointer points to something or not
        if (head == NULL)
        {
            // if it doesn't then point head to the initial node
             head = n;
        }
        else
        {
            node* x = head;
            
            while (x->next != NULL)
            {
                // iterating the new node pointer till then end
                x = x->next;
            }
            
            // storing the node at the end of the list
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

// node* concatenate(node* head1,node* head2){
//     // well not needed but you can get it from previous question
// }

node* sortedConcatenate(node* head1,node* head2){
    // Implement the required logic here
    
    // if list 1 is empty then return list 2 and vice versa
    if (head1 == NULL)
    {
        return head2;
    }
    
    if (head2 == NULL)
    {
        return head1;
    }

    // creating a new list which will have the sorted values
    
    node* mergedHead = NULL;
    
    // finding the initial element of this new list which will be smaller of the two
    if (head1->val <= head2->val)
    {
        mergedHead = head1;
        head1 = head1->next;
    }
    else
    {
        mergedHead = head2;
        head2 = head2->next;
    }
    
    // creating a tail pointer for this new list and adding new elements at this position
    node* tail = mergedHead;
    
    while(head1 != NULL && head2 != NULL)
    {
        // appending the smallest value to the new list
        if (head1->val <= head2->val)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        
        tail = tail->next;
    }
    
    // whichever list ends first, the elements of the other list are linked to the merged list
    if (head1 == NULL)
    {
        tail->next = head2;
    }
    else if (head2 == NULL)
    {
        tail->next = head1;
    }
    
    return mergedHead;
    
}

int main(){
    // Initialize two linked lists
    LinkedList l1;
    LinkedList l2;

    // take input and make the linked lists
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

    // call the sortedConcatenate function
    
    l1.head = sortedConcatenate(l1.head, l2.head);
    

    // print the new sorted big linked list using printLinkedList
    l1.printLinkedList();
    
    return 0;
}
