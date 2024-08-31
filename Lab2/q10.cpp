// Given a list L of Linked-Lists, Find 
// The number of pairs of heads that LEAD TO A HIT
// The number of pairs of heads that LEAD TO A FORK
// The number of pairs of heads that STAY APART

// Ordering of the heads in a pair is insignificant.

// 2 Linked List heads h1 and h2 are said to - 
// LEAD TO A FORK if a common node (other than h1 and h2) is reachable from both of them.
// STAY APART if they do not LEAD TO A FORK and neither of the heads is reachable from the other. 
// Formally, h1 cannot be reached from h2 and h2 cannot be reached from h1.
// LEAD TO A HIT if either h1 is reachable from h2, or h2 is reachable from h1

// Each node a is uniquely described by it’s id a_i

// Input format : 
// You just need to complete the function void printHitForkApart(vector& L)
// which accepts a vector of Linked List objects (class description provided).

// Output format : 
// Print three integers in a newline : 
// The number of pairs of heads that LEAD TO A HIT,
// The number of pairs of heads that LEAD TO A FORK,
// The number of pairs of heads that STAY APART

// Constraints : 
// 1 <= |L| <= 100
// 1 <= a_i <= 1e9
// All nodes have distinct id
// You may assume that none of the linked lists contain a cycle
// Heads of all linked lists are unique

// Input (Console, if you’re willing to test on additional test cases) : 
// First line contains integer n = |L|
// Each of the n lines that follow describe n linked lists : 
// Line i (1<=i<=n) contains m as the first integer (length of the linked list), the head’s id as the second integer, 
// while the remaining m-1 integers represent the id’s of the elements succeeding the head in order.

// Example:
// 7
// 6 1 2 3 4 5 6
// 4 3 4 5 6
// 5 7 3 4 5 6
// 1 6
// 3 8 9 6
// 3 12 13 14
// 5 10 11 12 13 14

// Precisely, 
// L = [[1,2,3,4,5,6,NULL],
//      [3,4,5,6,NULL],
//      [7,3,4,5,6,NULL],
//      [6,NULL],
//      [8,9,6,NULL],
//      [12,13,14,NULL],
//      [10,11,12,13,14,NULL]]	

// // Input reading and creation of Linked List vector is already done for you, please focus on completing the function only.

// Output
// 7
// 4
// 10

// Explanation 
// https://drive.google.com/file/d/1f1k8o1-_0vTN_j7a6nUml0n32ZxoWG4-/view?usp=sharing

// Node 1 and Node 3 hit
// Node 1 and Node 6 hit
// Node 3 and Node 7 hit
// Node 3 and Node 6 hit
// Node 7 and Node 6 hit
// Node 6 and Node 8 hit
// Node 12 and Node 10 hit

// Nodes 1 and 7 fork at node 3
// Nodes 1 and 8 fork at node 6
// Nodes 3 and 8 fork at node 6
// Nodes 7 and 8 fork at node 6

// All other remaining pairs of heads stay apart


#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int id; node* next;

    node(int ai){
        id = ai; next = NULL;
    }
} node;

class LinkedList{
public:
    node* head; node* last;

    LinkedList(node* h){
        head = h;
        last = h;
    }

    void insert(node* ln){
        last->next = ln;
        last = last->next;
    }

    void DisplayList(){
        for(node* c=head;c;c=c->next) cout << c->id << ' ';
        cout << '\n';
    }

    bool find(node* n){
        for(node* c=head;c;c=c->next)
            if(c==n) return true;
        return false;
    }
    
    unordered_set<int> reachable(){
        unordered_set<int> reach;
        
        node* x = head;
        while (x != nullptr)
        {
            reach.insert(x->id);
            x = x->next;
        }
        
        return reach;
    }
};

void printHitForkApart(vector<LinkedList>& L){
    int n = L.size();
    // for(auto x : L) x.DisplayList();

    // Complete the function now
    // Hint : Use the find method of Linked List
    
    int countForks = 0;
    int countHits = 0;
    int countAparts = 0;
    
    vector<unordered_set<int>> rsets(n);
    
    for (int i = 0; i < n; i++)
    {
        rsets[i] = L[i].reachable();
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            bool hit = false, fork = false;
            
            if (rsets[i].count(L[j].head->id) || rsets[j].count(L[i].head->id))
            {
                hit = true;
            }
            
            if (hit == false)
            {
                for (const int &z: rsets[i])
                {
                    if (z != L[i].head->id && z != L[j].head->id && rsets[j].count(z))
                    {
                        fork = true;
                        break;
                    }
                }
            }
            
            if (hit == true)
            {
                countHits++;
            }
            else if (fork == true)
            {
                countForks++;
            }
            else
            {
                countAparts++;
            }
            
            // for (node* c = L[j].head; c; c = c->next)
            // {
            //     if (L[i].find(c))
            //     {
            //         // countHits++;
            //     }
            // }
        }
    }
    
    
    cout << countHits << endl;
    cout << countForks << endl;
    cout << countAparts << endl;
    
}

// DO NOT ALTER THE CODE BELOW

int main(){
    int n; cin >> n;

    vector<LinkedList> LL;
    map<int,node*> mp;

    for(int i=0;i<n;i++){
        int m; cin >> m;
        int hid; cin >> hid; m--;
 
        if(mp.find(hid)==mp.end()) mp[hid] = new node(hid);
            LL.push_back(LinkedList(mp[hid]));
    
        while(m--){
            int ai; cin >> ai;
            if(mp.find(ai)==mp.end()) mp[ai] = new node(ai);
            LL[i].insert(mp[ai]);
        }
    }

    printHitForkApart(LL);
    return 0;
}
