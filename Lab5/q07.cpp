// Create a given linked list (assume starts from 0 and have consecutive elements and then an array say ids which is a subset of the list. 
// Now return how many sets of consecutive elements of ids are present in the original list. 
// Or more specifically the task is to find how many groups of consecutive elements from ids also appear consecutively (when sorted in increasing order)  
// in the original list.

// If Input: list = [0,1,2,3,4], ids = [0,3,1,4]
// Output: 2
// Explanation: Sorted ID's array - [0,1,3,4]. 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two consecutive pairs.
// Similarly if ids = [0,3,1,2] or [0,1,2,3], then output will be 6 (0-1, 0-1-2, 0-1-2-3, 1-2, 1-2-3, 2-3)


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    
public:

    LinkedList() : head(nullptr) {}
    
    Node* returnHead(){
        return head;
    }
    // Function to append a new node to the linked list
    void append(int new_data) {
        Node* new_node = new Node(new_data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }
    
    bool areConsecutive(Node* head, const vector<int>& sub_ids) {
        Node* x = head;
        
        while (x != nullptr && x->data != sub_ids[0]) {
            x = x->next;
        }
        
        for (int i = 1; i < sub_ids.size(); i++) {
            if (x == nullptr || x->next == nullptr || x->next->data != sub_ids[i]) {
                return false;
            }
            x = x->next;
        }
        return true;
    }
};

int countConsecutive(LinkedList linkedList,const vector<int>& ids, int n) {
    int count = 0;
    vector<int> sorted_ids = ids;
    sort(sorted_ids.begin(), sorted_ids.end());

    int m = sorted_ids.size();
    
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j <= m; j++) {
            vector<int> sub_ids(sorted_ids.begin() + i, sorted_ids.begin() + j);
            if (sub_ids.size() > 1 && linkedList.areConsecutive(linkedList.returnHead(),                                                                                        sub_ids)) 
            {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n;

    vector<int> list(n);
    for (int i = 0; i < n; i++)
        list[i] = i;

    cin >> m;

    vector<int> ids(m);
    for (int i = 0; i < m; i++)
        cin >> ids[i];
    
    sort(ids.begin(), ids.end());
    
    LinkedList linkedList;

    // Append elements to the linked list
    for (int i = 0; i < n; i++)
        linkedList.append(list[i]);

    // Calculate and print the count of consecutive elements
    cout << countConsecutive(linkedList ,ids, n) << endl;

    return 0;
}
