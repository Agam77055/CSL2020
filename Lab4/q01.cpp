// Ash has two binary trees, “Tree-1" and “Tree-2”, where each node of the tree has a positive integer value. 
// Now Ash wants to give these trees to Serena, but he can't decide which Tree should be gifted. 
// So to keep the good traits of both the trees, he decides to merge them in a common binary tree and gift this merged tree to Serena.
// But since Ash is good in catching Pokemons and not in coding, you need to help him in merging these binary trees.

// Rules:

// 1. If two nodes overlap, the sum of their values should be the new value of the merged node and 
// If either node in the overlapping position is null, the non-null node should be used as the value of the new node.

// 2. The binary tree contains only positive integer elements. -1 denotes a null node.

// Input Format:
// First line contains a single integer n, denoting the number of nodes in the 1st binary tree.
// Second line contains the n integers, nodes of the 1st binary tree in level order.
// Third line contains a single integer m, denoting the number of nodes in the 2nd binary tree.
// Fourth line contains the m integers, nodes of the 2nd binary tree in level order.

// Output Format:
// Print the inorder traversal of the merged binary tree.

// Sample Input:
// 7
// 1 2 3 -1 4 -1 5
// 7
// 1 2 2 6 -1 7 -1

// Output:
// 6 4 4 2 7 5 5


#include <bits/stdc++.h>
using namespace std;

//Getting faster
#define repeat(i,s,e) for(long long i=s;i<e;i++)
#define elif else if


class node {
    public:
    int data;
    node* left;
    node* right;
    
    node(): data(0), left(nullptr), right(nullptr) {}
    
    node(int val): data(val), left(nullptr), right(nullptr) {}
};

class binary_tree{
    public:
    node* root = nullptr;
    
    void make_binary_tree_from_array(int *arr, int size){
        this->root = construct_binary_tree_from_level_order_array(arr, 0, size);
    }
    
    node* construct_binary_tree_from_level_order_array(int *arr, int index, int size){
        if (index < size && arr[index] != -1) {
            node* newnode = new node(arr[index]);
            newnode->left = construct_binary_tree_from_level_order_array(arr, 2 * index + 1, size);
            newnode->right = construct_binary_tree_from_level_order_array(arr, 2 * index + 2, size);
            return newnode;
        }
        return nullptr;
    }
};


void inorder(node* root){
    /*
    Function for printing the inorder traversal
    Implement your logic here
    */
    vector<int> v;
    if (!root) return;
    
    stack<node*> st;
    node* x = root;
    
    while (x || !st.empty())
    {
        while(x)
        {
            st.push(x);
            x = x->left;
        }
        
        x = st.top();
        st.pop();
        
        v.push_back(x->data);
        
        x = x->right;
        
    }
    
    for (auto it: v)
    {
        cout << it << " ";
    }
    
}

node* merge_trees(node* root1,node* root2){
    /*
    Function for merging the two binary trees
    Implement your logic here
    */
    if (!root1 && !root2) return nullptr;
    if (!root1) return root2;
    if (!root2) return root1;
    
    node* newRoot = new node(root1->data + root2->data);
    
    newRoot->left = merge_trees(root1->left, root2->left);
    newRoot->right = merge_trees(root1->right, root2->right);
    
    // cout << newRoot->data << " ";
    // cout << newRoot->left->data << " ";
    // cout << newRoot->right->data << endl;
    return newRoot;
    
}

int main(){
    binary_tree tree1, tree2;
    int n,m;

    cin>>n;
    int arr[n];
    repeat(i,0,n) cin>>arr[i];
    tree1.make_binary_tree_from_array(arr,n);
    
    cin>>m;
    int brr[m];
    repeat(i,0,m) cin>>brr[i];
    tree2.make_binary_tree_from_array(brr,m);

    binary_tree merged_tree;
    merged_tree.root = merge_trees(tree1.root,tree2.root);
    inorder(merged_tree.root);

    return 0;
}
