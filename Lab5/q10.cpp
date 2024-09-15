// Alice is playing a game with a binary tree. The game proceeds as follows : 

// Initially, Alice chooses a random node from the binary tree.

// Then, he repeatedly moves to any of the nodes connected to the node he is currently on. 
// That is, if Alice is standing on node x, he may move to either the left child, right child or the parent of x, 
// whichever exists. Note that Alice must visit each node at most once.

// The game continues until Alice decides to quit due to being sleepy, or when he is unable to make any further moves.
// Whenever he steps on a new node, his score increases by the value at that node. Given that his initial score is zero, 
// what is the maximum possible score he can achieve?

// Input format : 
// The 1st line contains only an integer h, denoting the height of the Binary Tree.
// 2nd line contains 2h+1-1 integers representing the level order traversal of the Binary tree, where -1 represents NULL pointer.

// Output format : 
// A single integer equal to the maximum score achievable by Alice.

// Constraints 
// 1 <= x.id <= 100 for each node x in the tree.
// 1 <= h <= 11

// Example
// Input : 
// 3
// 5 4 8 11 -1 13 4 7 2 -1 -1 -1 -1 5 1

// Output : 
// 48

// Additional note:
// Input reading and tree creation has already been done for you. You only need to complete the member function   Solution::MaxScore(node* root)


#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    node* left; node* right;
    int id;
    node(int x){
        left = nullptr; right = nullptr;
        id = x;
    }
} node;


node* levelOrderToBT(vector<int>& v){

    vector<node*> nodes(v.size(), nullptr);
    for(int i=0;i<v.size();i++) if(v[i]!=-1) nodes[i] = new node(v[i]);

    for(int i=0;i<v.size();i++){
        if(v[i]==-1) continue;
        if(2*i+1<v.size() and v[2*i+1]!=-1) nodes[i]->left = nodes[2*i+1];
        if(2*i+2<v.size() and v[2*i+2]!=-1) nodes[i]->right = nodes[2*i+2];
    }

    return nodes[0];

}
// DO NOT ALTER THE CODE ABOVE.

class Solution {
public:
    int MaxScore(node* root)
    {
        int maxSum = INT_MIN;
        findMax(root, maxSum);
        return maxSum;
    }
    
private:
    int findMax(node* node, int& maxSum) {
        if (!node) return 0;
        
        int left = max(0, findMax(node->left, maxSum));
        int right = max(0, findMax(node->right, maxSum));
        
        maxSum = max(maxSum, left + right + node->id);
        
        return max(left, right) + node->id;
    }
};


// DO NOT ALTER THE CODE BELOW.

int main(){

    int h; cin >> h;
    vector<int> v((1<<(h+1))-1,-1);
    for(int & i : v) cin >> i;

    node* root = levelOrderToBT(v);

    Solution sol;
    cout << sol.MaxScore(root);


    return 0;
}
