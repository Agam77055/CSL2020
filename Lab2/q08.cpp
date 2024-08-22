// Given an unsorted linked list, your task is to return the second-highest element in the list. 
// If the list contains less than two distinct elements, return NULL.

// Input Format:
// First line of input contains an integer n, representing the number of elements in the linked list initially.
// A second line contains n space-separated integers representing the elements of the linked list.

// Output Format:
// The code should print the second highest element in the linked list and if there are less than 2 elements in the linked list, it should output "NULL".

// Sample Test Case:
// Input:
// 5
// 4 7 2 6 9

// Output:
// 7

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)

class node {
public:
    // Define node attributes.
    int val;
    node* next;
    node(int val = 0, node* next = NULL)
    {
        this->val = val;
        this->next = next;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }

    void insert(int val){
        // Add the insertion logic here.
        
        // sorting the linked list in descending order while inserting the elmenets
        
        node* n = new node(val);
        
        if (head == NULL || head->val < n->val)
        {
            n->next = head;
            head = n;
        }
        else
        {
            node* x = head;
            while (x->next != NULL && x->next->val >= n->val) x = x->next;
            
            n->next = x->next;
            x->next = n;
        }
    }

    void printLinkedList() {
        if (head == NULL) {
            cout << "EMPTY\n";
            return;
        }
        node* curr = head;
        while (curr) {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << "NULL\n";
    }

    node* second_highest() {
        // Add the logic to obtain second highest element here.
        
        // iterating through the list to find the second highest element
        node* x = head;
        while (x->next != NULL && x->next->val == x->val) x = x->next;
        
        // if no second element exists, then return NULL
        if (x->next == NULL)
        {
            return NULL;
        }
        
        return x->next;
    }
};

int main() {
    // Initialize the linked list.
    LinkedList list;
    
    // Take the input to linked list.
    int n;
    cin>>n;
    
    if (n < 2)
    {
        cout << "NULL";
        return 0;
    }
    
    FOR(i, n)
    {
        int num;
        cin>>num;
        
        list.insert(num);
    }
    
    node* result = list.second_highest();

    if (result) {
        cout << result->val << endl;
    } else {
        cout << "NULL" << endl;
    }
    
    // cout << result->val;
    // list.printLinkedList();

    return 0;
}
