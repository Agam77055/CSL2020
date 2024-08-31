// Julian is running a game show, but people's interest has been declining. To make the game show exciting,
// he decides to "fix" the results and write a good script for the show to make it more entertaining. The format of the show is as follows:

// There are 2 contestants, each of which get to either get the next reward or pass to the other contestant. 
// Once passed, the chance to get rewards does not revert to the contestant until the other contestant passes his/her reward. 
// (Both cannot simultaneously pass a reward). Each reward can be positive, negative or zero integer.

// Julian wants to fix the rewards, such that there are "exactly" 2 "passes", and the game ends in a tie. Can you help Julian determine if a given sequence of rewards is "fixable"?

// Input:
// Number of questions in the round "n"
// The points scored for the reward

// Output:
// Number of ways to fix the round. 

// E.g.1:
// Input - 
// 6
// -16 1 5 -6 7 9
// Output - 
// 1

// E.g.2:
// Input - 
// 5
// 1 5 -6 7 9
// Output - 
// 0

// Explanation i) The possible sets of passes include {2,5}, which makes each contestants total -16 + 7 + 9 = 1 + 5 + (-6) = 0 
// ii) No way to tie up the scores in 2 passes (possible with 3 passes, {2,4,5}, but not 2)

// (Hint: Similar to finding 1 pass division)


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    int size;
    Node* root;
    
    LinkedList() : size(0), root(nullptr) {}
    
    ~LinkedList() {
        while (root != nullptr) {
            Node* temp = root;
            root = root->next;
            delete temp;
        }
    }
    
    void push(int value) {
        Node* node = new Node(value);
        if (root == nullptr) {
            root = node;
        } else {
            Node* x = root;
            while (x->next != nullptr) {
                x = x->next;
            }
            x->next = node;
        }
        size++;
    }
    
    int solution() {
        // if (size < 3) {
        //     return 0;
        // }
        
        // int totalSum = calculateTotalSum();
        
        // if (totalSum % 2 != 0) {
        //     return 0;
        // }
        
        // int target = totalSum / 2;
        
        // vector<int> prefixSums = calculatePrefixSums();
        
        // // for (int i = 0; i < prefixSums.size(); i++)
        // // {
        // //     cout << prefixSums[i] << " ";
        // // }
        
        // // cout << endl;
        // // cout << target << endl;
        
        // int countPass = 0;
        // int countWays = 0;
        
        // for (int j = 1; j <= size; j++) {
        //     if (prefixSums[j - 1] == target) {
        //         countPass++;
        //     }
        //     if (prefixSums[j] == 2*target) {
        //         countWays += countPass;
        //     }
        // }
        
        // return countWays;
        
        Node * fs = root;
        int count = 0;
        
        while (fs->next != nullptr)
        {
            Node* ss = fs->next;
            while (ss != nullptr)
            {
                int sum1 = 0;
                int sum2 = 0;
                
                Node* temp = root;
                while (temp != fs->next)
                {
                    sum1 += temp->data;
                    temp = temp->next;
                }
                
                while (temp != ss->next)
                {
                    sum2 += temp->data;
                    temp = temp->next;
                }
                
                while (temp != nullptr)
                {
                    sum1 += temp->data;
                    temp = temp->next;
                }
                
                if (sum1 == sum2)
                {
                    count++;
                }
                
                ss = ss->next;
            }
            
            fs = fs->next;
        }
        
        return count;
    }
};

int main() {
    LinkedList L;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        L.push(num);
    }
    
    cout << L.solution();
    
    return 0;
}
