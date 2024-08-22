// Given an array of elements, insert all the elements in a Linked List in sorted order. 
// The insertion function should be called everytime you add an element to the linked list and it should be implemented in such a way 
// that the inserted element goes to its correct position in the sorted order.
// NOTE : You must NOT sort the array and then create a Linked List.

// Input Format : First line of the input contains an integer 'n', representing the size of the input array.
// Next line contains n integers representing the elements in the array.

// Output Format : Print the elements in the sorted linked list.

// Example Input : 
// 5
// 3 11 9 16 15
// Example Output : 
// 3 9 11 15 16


#include <bits/stdc++.h>
using namespace std;

class node {
public:
    // Define node attributes here.
    int data;
    node* next;
    node(int data = 0, node* next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }
    
    void insert_sorted(int val) {
        // Add insertion logic here.
        node* n = new node(val);
        
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node* x = head;
            
            if (n->data < x->data)
            {
                head = n;
                head->next = x;
                return;
            }
            
            while (x->next != NULL && n->data > x->next->data)
            {
                x = x->next;
            }
            
            n->next = x->next;
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
            cout<<curr->data<<' ';
            curr = curr->next;
        }
        cout<<"NULL\n";
    }
};

int main() {
    node* head;
    
    LinkedList list(head);
    
    int n;
    cin>>n;
    
    int num;
    
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        list.insert_sorted(num);
    }
    
    list.printLinkedList();
    
    // Add your code here.

    return 0;
}
