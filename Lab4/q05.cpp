// WAP to implement the insertion of nodes into an AVL tree and check whether the resulting tree is a valid AVL tree. 
// Your main program should take the following input:
// The number of nodes n to be inserted into the AVL tree. n integers representing the data of each node to be inserted.

// Inputs: number of nodes and value of nodes.
// Output: root node of resultant and "True " or "False" to represent validity.

// input: 2 1 3
// output :
// 2 1 3 
// True


#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// Class for AVL Tree Node
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    // Constructor to initialize a new AVL tree node
    Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Function to get the height of a node
int getHeight(Node* node) {
    // Implement this function to return the height of a node
    if (!node) return 0;
    return node->height;
}

// Function to create a new AVL tree node
Node* createNode(int data) {
    return new Node(data);
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    // Implement this function to perform a right rotation
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    // Implement this function to perform a left rotation
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

// Get Balance factor of node N
int getBalance(Node* N) {
    // Implement this function to calculate and return the balance factor
    if (!N) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

// Function to insert a node in AVL tree and balance the tree
Node* insert(Node* node, int key) {
    // Implement this function to insert a node and balance the AVL tree
    
    if (node == nullptr) return createNode(key);

    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    if (balance > 1 && key > node->left->key) 
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    if (balance < -1 && key < node->right->key) 
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to check if a tree is a valid AVL tree
bool isValidAVL(Node* root) {
    // Implement this function to check if a tree is a valid AVL tree
    if (!root) return true;
    
    int balance = getBalance(root);
    
    if (balance > 1 || balance < -1) return false;
    
    return isValidAVL(root->left) && isValidAVL(root->right);
    
}

// Function to perform preorder traversal of the AVL tree
void preorderTraversal(Node* root) {
    // Implement this function to perform a preorder traversal and print nodes
    if (!root) return;
    cout << root->key << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


int main() {
    int n;

    cin >> n;
    Node* root = nullptr;


    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }


    preorderTraversal(root);
    cout << endl;

    if (isValidAVL(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
