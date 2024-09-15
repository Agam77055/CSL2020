// Given a linked list, return an array greater[] where every ith element of greater contains the node value of the linked list 
// which is strictly greater than the ith node (1 indexed). If a greater node is not available, it is set to 0.

// Example, given following list input : [2, 7, 4, 3, 5]
// Returns : [7, 0, 5, 5, 0]


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;
    
    Node(int data): data(data), next(nullptr) {}
};

// LinkedList class for the main linked list operations
class LinkedList {
private:
    Node* head = nullptr;

public:

    void append(int data)
    {
        Node* n = new Node(data);
        if (!head) head = n;
        else
        {
            Node* x = head;
            while (x->next) x = x->next;
            
            x->next = n;
        }
    }

    // Function to calculate the greater array
    vector<int> calculateGreater(int size) { 
        
        Node* x = head;
        vector<int> great(size, 0);
        
        vector<int> elements;
        
        while (x)
        {
            elements.push_back(x->data);
            x = x->next;
        }
        
        stack<int> st;  // stack to store indices of nodes
        
        for (int i = 0; i < size; i++) {
            while (!st.empty() && elements[st.top()] < elements[i]) {
                great[st.top()] = elements[i];
                st.pop();
            }
            st.push(i);
        }
        
        return great;
    }

    // Function to print the linked list
    void printList() {
        
    }
};

int main() {
    int size;
    cin >> size;

    LinkedList list;

    // Input the elements of the linked list
    for (int i = 0; i < size; i++) {
        int data;
        cin >> data;
        list.append(data);
    }

    // Calculate the greater array
    vector<int> greater = list.calculateGreater(size);

    // Output the greater array
    for (int i = 0; i < size; i++) {
        cout << greater[i] << " ";
    }
    cout << endl;

    return 0;
}
