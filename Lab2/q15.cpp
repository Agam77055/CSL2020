// You are provided with a doubly linked list and an integer key. Your task is to remove all occurrences of the key from the list only if it appears at least twice. 
// If the key appears less than twice, the list should remain unchanged.

// Input Format:
// First line of the input contains an integer n representing the number of elements in the doubly linked list.
// Next line contains series of integers to be inserted into the doubly linked list.
// The last line contains single integer representing the key whose occurrences need to be deleted if it appears at least twice.

// Output Format:
// Print the modified linked list after performing the deletion operation, if applicable.

// Example Input:
// 6
// 1 2 2 3 5 4
// 2

// Example Output:
// 1 3 5 4

#include <iostream>
using namespace std;

// Definition for a doubly linked list node.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to insert a node at the end of the doubly linked list.
void insert(Node*& head, int data) {
    // Complete this function.
    Node* n = new Node(data);
    
    if (head == nullptr)
    {
        head = n;
    }
    else
    {
        Node* x = head;
        
        while (x->next != nullptr)
        {
            x = x->next;
        }
        
        // since it is a doubly LL, we will also  have to assign the previous of this new node;
        x->next = n;
        n->prev = x;
    }
    
}

// Function to delete all occurrences of a key if it appears at least twice in the doubly linked list.
void deleteIfOccursTwice(Node*& head, int key) {
    // Complete this function.
    Node *x = head;
    
    int count = 0;
    
    // counting the how many times 'key' is repeated in the list
    while (x != nullptr)
    {
        if (x->data == key)
        {
            count++;
        }
        
        x = x->next;
    }
    
    // if key is present only one time, return the list;
    if (count < 2)
    {
        return;
    }
    
    x = head;
    
    // removing the key if it appears twice in the list
    while (count)
    {
        if (x->data == key)
        {
            Node* temp  = x;
            
            // if key is at the head, we will shift the head to the next element
            if (x == head)
            {
                head = head->next;
                
                if (head != nullptr)
                {
                    head->prev = nullptr;
                }
                
                x = head;
            
                count--;
            }
            else
            {
                // if key is in the middle of the list, we will assign the previous element of
                // x to the next element of x and vice versa
                
                x->prev->next = x->next;
                if (x->next != nullptr)
                {
                    x->next->prev = x->prev;
                }
                
                x = x->next;
                
                // cout << x->data << " ";
                
                count--;
                
            }
            
            // freeing the element from the memory
            delete temp;
        
        }
        else
        {
            x = x->next;
        }
    }
}

// Function to print the doubly linked list.
void printList(Node* head) {
    if (head == nullptr)
    {
        return;    
    }
    
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n; cin >> n;
    Node* head = nullptr;

    for(int i=0; i<n; i++){
        int t; cin >> t;
        insert(head, t);
    }

    int key; cin >> key;
    deleteIfOccursTwice(head, key);

    printList(head);

    return 0;
}
