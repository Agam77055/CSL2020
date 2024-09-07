// Given the root of a binary tree, invert the tree such that the left and right subtrees are swapped. 

// Each node in the tree has a unique integer value. Write a CPP program to invert the binary tree.

// INPUT FORMAT : 
// The input consists of two lines:
// 1. The first line contains an integer n, representing the number of nodes in the tree.
// 2. The second line contains n integers, representing the level-order traversal of the tree. 
// -1 has been used to denote NULL nodes (i.e., positions where the tree does not have a node).

// Example Input : 
// 7
// 4 2 7 1 3 6 9

//         4
//        / \
//       2   7
//      / \  / \
//     1  3 6  9	

// OUTPUT FORMAT:
// The output consists of two lines:
// 1. The first line contains the pre-order traversal of the tree before inverting it.
// 2. The second line contains the pre-order traversal of the tree after inverting it.

// Example Output : 
// 4 2 1 3 7 6 9 
// 4 7 9 6 2 3 1 
					
//         4
//        / \
//       7   2
//     / \   / \
//     9  6 3  1


#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

    // Destructor to clean up dynamically allocated nodes
    ~TreeNode() {
        delete left;
        delete right;
    }
};

// Function to create a new node
TreeNode* createNode(int value) {
    if (value == -1) return nullptr; // -1 is used to denote null nodes
    return new TreeNode(value);
}

// Function to insert nodes in level order
TreeNode* insertLevelOrder(vector<int>& arr, int i, int n) {
    // Given an array representation of a tree, construct the binary tree
    // TODO: Implement the function

    if (i < n && arr[i] != -1)
    {
        TreeNode* node = createNode(arr[i]);
        
        node->left = insertLevelOrder(arr, 2*i + 1, n);
        node->right = insertLevelOrder(arr, 2*i + 2, n);
        
        return node;
    }
    
    return nullptr;

}

// Function to invert the binary tree
TreeNode* invertTree(TreeNode* root) {
    // Swap the left and right children of every node in the tree
    // TODO: Implement the function
    
    if (!root) return nullptr;
    
    TreeNode* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    
    return root;
}

// Function to print the tree in pre-order
void printPreorder(TreeNode* root) {
    // Print the nodes of a binary tree in preorder
    // TODO: Implement the function
    vector<int> v;
    if (!root) return;
    
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        
        v.push_back(node->value);
        
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    
    for (auto it: v)
    {
        cout << it << " ";
    }
}

int main() {
    // DO NOT MODIFY THIS
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    TreeNode* root = nullptr;
    root = insertLevelOrder(arr, 0, n);

    // Print the original tree in pre-order
    printPreorder(root);
    cout << endl;

    // Invert the tree and print again
    root = invertTree(root);
    printPreorder(root);
    cout << endl;

    // Clean up memory
    delete root;

    return 0;
}
