// Create a BST from given inputs (+ve) and find the in-order successor for the given element and if no successor is there print -1.
// Input: n
// n number of inputs element whose successor needs to be printed

// Input: 1)number of nodes and values ; 2) target node sought for successor
// Output : successor node

#include <bits/stdc++.h>
using namespace std;

// Class definition for a Node in the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class definition for the Binary Search Tree
class BST {
private:
    Node* root;

    // Helper function to insert a node in the BST
    Node* insert(Node* node, int data) {
        // TODO: Implement the insert function
        if (!node) return new Node(data);
        if (data < node->data) node->left = insert(node->left, data);
        else if (data > node->data) node->right = insert(node->right, data);
        
        return node;
    }

    // Helper function to find the minimum value node in a subtree
    Node* findMin(Node* node) {
        // TODO: Implement the findMin function
    }

    // Helper function to find a node with a given value
    Node* findNode(Node* node, int data) {
        // TODO: Implement the findNode function
    }

public:
    // Constructor to initialize the root of the BST
    BST() {
        root = nullptr;
    }

    // Public function to insert a node in the BST
    void insert(int data) {
        root = insert(root, data);
    }

    // Function to find the in-order successor of a given node
    int findInOrderSuccessor(int data) {
        // TODO: Implement the findInOrderSuccessor function
        
        vector<int> v;
        stack<Node*> st;
        Node* x = root;
        
        while (x || !st.empty())
        {
            while (x)
            {
                st.push(x);
                x = x->left;
            }
            
            x = st.top();
            st.pop();
            
            v.push_back(x->data);
            x = x->right;
        }
        
        for (int i = 0; i < v.size(); i++)
        {
            if (i == v.size() - 1) return -1;
            if (v[i] == data)
            {
                return v[i+1];
            }
        }
    }
};

// Main function to execute the program
int main() {
    int n, target;
    cin >> n;

    BST tree;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cin >> target;

    int successor = tree.findInOrderSuccessor(target);
    if (successor != -1) {
        cout << successor << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
