// You are given a binary tree in the form of an array.
// Return 'true' if it is a height-balanced binary tree. Your task is to first construct a Binary Tree and then check whether it is a height-balanced tree or not.

// Note:
// The input tree is given in level order.
// Null is represented by -1 in the input
// The height of a tree is the maximum number of nodes in a path from the node to the leaf node.

// Inputs : 
// First line of input is the number of elements in tree including null
// Second line of input contains all the elements

// Sample Input 1:
// 11
// 1 2 3 4 -1 -1 -1 -1 5 -1 -1

// Expected Answer:
// false


// Sample Input 2:
// 11
// 1 2 3 4 -1 -1 5 -1 -1 -1 -1

// Expected Answer:
// true


#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:

    TreeNode* root;
    
    BinaryTree(): root(nullptr) {}
    
    void create(const vector<int> arr)
    {
        if (arr.empty() || arr[0] == -1) return;
        
        root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        int size = (int) arr.size();
        
        while (!q.empty() && i < size)
        {
            TreeNode *node = q.front();
            q.pop();
            
            if (i < size && arr[i] != -1)
            {
                node->left = new TreeNode(arr[i]);
                q.push(node->left);
            }
            i++;
            
            if (i < size && arr[i] != -1)
            {
                node->right = new TreeNode(arr[i]);
                q.push(node->right);
            }
            i++;
        }
        
        
    }
    
    int checkHeight(TreeNode* node)
    {
        if (!node) return 0;
        
        int left = checkHeight(node->left);
        if (left == -1) return -1;
        
        int right = checkHeight(node->right);
        if (right == -1) return -1;
        
        if (abs(left - right) > 1) return -1;
        
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        if (checkHeight(root) != -1) return true;
        else return false;
    }
    
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    BinaryTree tree;
    tree.create(arr);
    
    cout << (tree.isBalanced(tree.root) ? "true" : "false") << endl;

    return 0;
}
