// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that 
// adding up all the values along the path equals targetSum.

// A leaf is a node with no children.

// Inputs : 
// First line of input is the number of elements in tree including null
// Second line of input contains all the elements
// Third line of input is the targetSum.

// Constraints:
// 1 <= nodeVal <= 1000

// Sample Input 1:
// 11
// 3 1 9 -1 -1 6 10 -1 -1 -1 -1
// 4

// Sample Output 1:
// true


// Sample Input 2:
// 9
// 2 1 4 -1 -1 3 -1 -1 -1
// 11

// Sample Output 2:
// false


#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
    
    
    
};

TreeNode* buildTree(const std::vector<int>& nodes) {
    if (nodes.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int) nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < (int) nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

bool isPathSum(TreeNode* root, int targetSum) {
    vector<int> arr;
    if (!root) return false;
    
    stack<TreeNode*> st;
    st.push(root);
    
    int sum = 0;
    
    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        
        arr.push_back(node->value);
        sum += node->value;
        
        if (!node->left && !node->right)
        {
            if (sum == targetSum)
            {
                return true;
            }
            else
            {
                sum -= node->value;
            }
        }
        
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    
    // for (auto it: arr)
    // {
    //     cout << it << " ";
    // }
    
    return false;;
}

int main() {
    int n, targetSum;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> targetSum;

    TreeNode* root = buildTree(arr);

    bool result = isPathSum(root, targetSum);
    cout << (result ? "true" : "false")<<"\n";

    delete root;

    return 0;
}
