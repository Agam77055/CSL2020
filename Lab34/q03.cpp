// Write a program which takes two binary tree as input (in the form of an array)  and checks if they are same or not. 
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value. 
// The tree structure will be given in an array form, where the left and right children of the node at array index i 
// are at array index 2*i + 1 and 2*i + 2 respectively. (use -1 for null nodes) 

// Note: Do NOT compare the array form inputs to give your output. Convert the 2 arrays to 2 BTs, and compare them.

// Example: p:
//                   2
//                 /   \
//               1     3
//    q:
//          2
//        /    \
//      1      3

// Input:
// 2 1 3
// 2 1 3
// Output: 1 (True)

// Example:  p:
//                   2
//                 /   
//               1     
//    q:
//          2
//           \
//            1
// Input:
// 2 1 
// 2 -1 1
// Output : 0 (False)


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new tree node
TreeNode* newNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Function to build a binary tree from an array
TreeNode* buildTreeFromArray(int arr[], int index, int size) {
    // Implement the function here
    if (index < size && arr[index] != -1)
    {
        TreeNode* node = newNode(arr[index]);
        node->left = buildTreeFromArray(arr, 2 * index + 1, size);
        node->right = buildTreeFromArray(arr, 2 * index + 2, size);
        return node;
    }
    return nullptr;
}

// Function to check if two binary trees are identical
bool areIdentical(TreeNode* root1, TreeNode* root2) {
    // Implement the function here
    if (!root1 && !root2) return true;
    
    if (!root1 || !root2 || root1->data != root2->data)
    {
        return false;
    }
    
    return areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
}

// Function to build a binary tree from a string in the array format
TreeNode* buildTreeFromArrayString(const string& str) {
    // Implement the function here
    vector<int> arr;
    stringstream ss(str);
    string temp;
    
    while (getline(ss, temp, ' ')) {
        if (temp == "-1") {
            arr.push_back(-1);
        } else {
            arr.push_back(stoi(temp));
        }
    }
    
    TreeNode* node = buildTreeFromArray(arr.data(), 0, arr.size());
    return node;
}

int main() {
    // Get the array input for the first tree from the user
    string input1;
    getline(cin, input1);

    // Create binary tree from the first input
    TreeNode* root1 = buildTreeFromArrayString(input1);

    // Get the array input for the second tree from the user
    string input2;
    getline(cin, input2);

    // Create binary tree from the second input
    TreeNode* root2 = buildTreeFromArrayString(input2);

    // Check if the trees are identical
    if (areIdentical(root1, root2)) {
        cout << "1"; // 1 for identical
    } else {
        cout << "0"; // 0 for not identical
    }

    // Free allocated memory
    // Implement freeing memory here

    return 0;
}
