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
// ListNode* reverseList(ListNode* head, int B) {
//     // TODO: Implement the logic to reverse B nodes of the linked list
//     return nullptr; // Placeholder return statement
// }

ListNode* reverseAlternateBNodes(ListNode* A, int B) {
    // TODO: Implement logic to reverse every alternate group of B nodes
    // ListNode* x = A;
    // int count = 1;
    
    // ListNode* temp = A;
    
    // while(x != nullptr)
    // {
    //     if (count == B)
    //     {
    //         count = 0;
            
    //         int tmp = temp->val;
    //         temp->val = x->val;
    //         x->val = tmp;
            
    //         temp = x->next;
    //     }
        
    //     x = x->next;
    //     count++;
    // }
    
    // return A;
    
    ListNode* x = A;
    
    int count1 = 1;
    int count2 = 0;
    
    ListNode* temp = A;
    
    while (x != nullptr)
    {
        if (count1 % B == 0)
        {
            count2++;
        }
        
        if (count2 % 2 == 1)
        {
            int tmp = temp->val;
            temp->val = x->val;
            x->val = tmp;
            
            temp = x;
        }
        
        
        cout << count1 << " " << count2 << endl;
        
        x = x->next;
        count1++;
    }
    
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
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}
int main() {
    ListNode* head = nullptr;
    int n, value, B;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        append(head, value);
    }
    std::cin >> B;
    head = reverseAlternateBNodes(head, B);
    printList(head);

    return 0;
}
