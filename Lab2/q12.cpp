// Given a LL as shown below. It has a list within a list:
// 1->{3->4->5}->{10->7->8}->5->{11->13}->15
// INPUT: first line of input is number of sublists=n
// 2.n line of inputs conatain:
// 3. size of  sublist
// 4. linked list of size sublist

// head pointer of each linked list passed to the vector.

// Assume that every sub-element of a sub-list is in a new level. Now output the list level-wise. Like:

// 1->3->10->5->11->15->4->7->13->5->8

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode* sublist;

    ListNode(int x) : val(x), next(nullptr), sublist(nullptr) {}
};

// Function to combine elements of all sublists level by level
ListNode* combineListsLevelByLevel(vector<ListNode*>& subLists) {
    // Create a new head node for the combined list
    ListNode* newHead = new ListNode(0);
    ListNode* current = newHead;

    queue<ListNode*> q;

    for (ListNode* head : subLists) {
        if (head) {
            q.push(head);
        }
    }

    // Process nodes in the queue
    while (!q.empty()) {
        // Dequeue a node
        ListNode* node = q.front();
        q.pop();

        // Add the node's value to the new list
        current->next = new ListNode(node->val);
        current = current->next;

        // Enqueue the node's next node (if it exists)
        if (node->next) {
            q.push(node->next);
        }
    }

    return newHead->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<ListNode*> subLists(n, nullptr);

    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        for (int j = 0; j < size; ++j) {
            int val;
            cin >> val;
            current->next = new ListNode(val);
            current = current->next;
        }

        subLists[i] = dummy->next;
    }

    ListNode* combinedHead = combineListsLevelByLevel(subLists);

    printList(combinedHead);

    return 0;
}
