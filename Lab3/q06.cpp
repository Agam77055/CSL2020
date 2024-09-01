// Given a linked list A of length N and an integer B. You need to reverse every alternate B nodes in the linked list A.
// Input Format: 
// 11
// 1 2 3 4 5 6 7 8 9 10 11 
// 3
// Output Format: 
// 3 2 1 4 5 6 9 8 7 10 11
// Explanation:
// B = 3,  so we reverse the first 3 nodes, leave the next 3 nodes as they are, reverse the next 3 nodes, and so on.

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* reverseList(ListNode* head, int B) {
    // TODO: Implement the logic to reverse B nodes of the linked list
    ListNode* prev = nullptr;
    ListNode* x = head;
    ListNode* nxt = nullptr;
    
    int count = 0;
    
    while(x != nullptr && count < B)
    {
        nxt = x->next;
        x->next = prev;
        prev = x;
        x = nxt;
        
        count++;
    }
    
    // cout << x->val << endl;
    
    if (head != nullptr)
    {
        head->next = x;
    }
    
    return prev; // Placeholder return statement
}

ListNode* reverseAlternateBNodes(ListNode* A, int B) {
    // TODO: Implement logic to reverse every alternate group of B nodes
    if (A == nullptr) return nullptr;
    
    if (B <= 1) return A;
    
    int count = 0;
    ListNode* c = A;
    while (c != nullptr)
    {
        count++;
        c = c->next;
    }
    
    if (B > count) return A;
    
    int counter = 0;
    
    ListNode* prev = nullptr;
    ListNode* x = A;
    
    bool flag = true;
    
    while (x != nullptr)
    {
        if (flag)
        {
            ListNode* tail = reverseList(x, B);
            
            if (prev != nullptr)
            {
                prev->next = tail;
            }
            else
            {
                A = tail;
            }
            
            // cout << x->val << endl;
            
            prev = x;
            x = x->next;
            
            counter += B;
            flag = false;
        }
        else
        {
            for (int i = 0; i < B && x != nullptr; i++)
            {
                prev = x;
                // cout << x->val << " ";
                x = x->next;
                counter++;
            }
            
            if (count - counter > B)
            {
                flag = true;
            }
        }
        
    }
    
    // A = reverseList(A, B);
    
    return A;
    
}
void append(ListNode*& head, int new_data) {
    ListNode* new_node = new ListNode(new_data);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    ListNode* last = head;
    while (last->next != nullptr) last = last->next;
    last->next = new_node;
}
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
int main() {
    ListNode* head = nullptr;
    int n, value, B;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        append(head, value);
    }
    cin >> B;
    head = reverseAlternateBNodes(head, B);
    if (head == nullptr) return 0;
    printList(head);

    return 0;
}
