// You are given a list of elements, including possible null values, to create a Binary Search Tree (BST). 

// Input:
// 1. Number of elements (N): An integer representing the total number of elements
// 2. Elements: A list of integers

// Output:
// Print the in-order traversal of the constructed BST, omitting the `null` values.

// Example:

// Input:
// Number of elements: 5
// Elements: 50, 30, 20, 40, 70

// Output:
// In-order Traversal: 20, 30, 40, 50, 70

// Explanation:
// The constructed BST is:
//        50
//       /  \
//     30   70
//    /  \
//  20   40

// Hence, the "in-order" traversal is => 20, 30, 40, 50, 70


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root = nullptr;
    
    Node* createBST(Node* node, int val)
    {
        Node* n = new Node(val);
        if (!node) return n;
        if (val <= node->data) node->left = createBST(node->left, val);
        else if (val > node->data) node->right = createBST(node->right, val);
        
        return node;
    }
    
    vector<int> inOrderTraversal()
    {
        vector<int> v;
        if (!root) return v;
        
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
        
        return v;
    }
};

int main() {
    int n;
    cin >> n;
    
    BST bst;
    
    while (n--)
    {
        int num;
        cin>>num;
        
        bst.root = bst.createBST(bst.root, num);
    }
    
    
    vector<int> inOrder = bst.inOrderTraversal();
    for (int val : inOrder) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
