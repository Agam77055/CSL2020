// Build an AVL tree by inserting a predefined set of keys.
// Allow the user to input a key to delete from the AVL tree.
// Perform the necessary rotations to maintain the AVL tree's balance after deletion.
// Display the tree's preorder traversal after the deletion to illustrate its balanced structure.

// Inputs: 1) a integer value which represents "Number of nodes"; 2) Take node values ;3) Another input which represents target node to delete.
// Output : Preorder traversal of tree


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    struct Node *left, *right;
    int height;
    
    Node(int key): key(key), left(nullptr), right(nullptr), height(1) {}

};

// Function to get height of the tree
int height(Node *N) {
    // TODO: Implement height function
    if (!N) return 0;
    
    return 1 + max(height(N->left), height(N->right));
}

// Helper function to create a new node with the given key
Node* newNode(int key) {
    // TODO: Allocate memory for a new node and initialize it
    return new Node(key);
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node *y) {
    // TODO: Implement rightRotate function
    Node* left_node = y->left;
    Node* temp = left_node->right;
    
    left_node->right = y;
    y->left = temp;
    
    y->height = max(height(y->left),height(y->right)) + 1;
    left_node->height = max(height(left_node->left),height(left_node->right)) + 1;
    
    return left_node;

}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node *x) {
    // TODO: Implement leftRotate function
    Node* right_node = x->right;
    Node* temp = right_node->left;
    
    right_node->left = x;
    x->right = temp;
    
    x->height = max(height(x->left),height(x->right)) + 1;
    right_node->height = max(height(right_node->left),height(right_node->right)) + 1;
    
    return right_node;

}

// Get Balance factor of node N
int getBalance(Node *N) {
    // TODO: Implement getBalance function
    if (!N) return 0;
    
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key into the subtree rooted with node
// and returns the new root of the subtree.
Node* insert(Node* node, int key) {
    // TODO: Implement AVL tree insertion logic
    // Remember to update the height of the node and balance the tree
    if(!node) return new Node(key);;
    
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;
    
    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    if (balance > 1 && key < node->left->key)
    { 
        node = rightRotate(node);  // right rotation
    }
    
    else if (balance < -1 && key > node->right->key)
    { 
        node = leftRotate(node);  // left rotation
    }
    
    else if (balance < -1 && key < node->right->key) 
    {
        node->right = rightRotate(node->right);  // right-left rotation
        node = leftRotate(node);
    }
    
    else if (balance > 1 && key > node->left->key) 
    {
        node->left = leftRotate(node->left); // left-right rotation
        node = rightRotate(node);
    }
    
    return node;

}

// Recursive function to delete a node with given key from subtree with given root
// It returns root of the modified subtree.
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
    {
        root = rightRotate(root);
        root->height = 1 + max(height(root->left), height(root->right));
    }
    else if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (balance < -1 && getBalance(root->right) <= 0)
    {
        root = leftRotate(root);
        root->height = 1 + max(height(root->left), height(root->right));
    }
    else if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


// A utility function to do preorder traversal of the tree
void preOrder(Node *root) {
    if(root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}



int main() {
    Node *root = NULL;
    int n, key;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>key;
        root = insert(root, key);
    }

    cin>>key;
    root = deleteNode(root, key);

    preOrder(root);

    return 0;
}
