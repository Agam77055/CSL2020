// Given a linked list head, remove all the duplicates from the list and return the final list in a  sorted order.
// input 1-2-3-3-4-4-5
// output : 1-2-5


#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
};

// Function to delete duplicate elements from a sorted singly-linked list
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return nullptr;

    ListNode dummy;  // Create a dummy node to handle edge cases
    dummy.next = head;
    ListNode* prev = &dummy; // Pointer to keep track of the previous node

    while (head) {
        bool hasDuplicate = false;

        // Check for duplicates
        while (head->next && head->val == head->next->val) {
            hasDuplicate = true;
            ListNode* duplicate = head->next;
            head->next = head->next->next;
            delete duplicate;
        }

        if (hasDuplicate) {
            // If duplicates were found, remove the current node as well
            ListNode* temp = head;
            prev->next = head->next;
            head = head->next;
            delete temp;
        } else {
            // Move the previous pointer forward if no duplicates found
            prev = head;
            head = head->next;
        }
    }

    return dummy.next;
}


// Function to print the elements of a singly-linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << " ";
        current = current->next;
    }
    cout << " ";
    cout << endl;
}

// Function to create a singly-linked list from a string of digits
ListNode* createList(const char* digits) {
    ListNode dummy;
    ListNode* tail = &dummy;
    dummy.next = nullptr;

    while (*digits) {
        ListNode* node = new ListNode();
        node->val = *digits - '0';
        node->next = nullptr;
        tail->next = node;
        tail = node;
        digits++;
    }

    return dummy.next;
}

// Function to free the memory allocated for a singly-linked list
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Read input: linked list elements in the form of a string of digits
    string input;
    cin >> input;

    // Create a linked list from the input
    ListNode* head = createList(input.c_str());

    // Print the original linked list
    printList(head);

    // Remove duplicates from the sorted list
    head = deleteDuplicates(head);

    // Print the modified list after removing duplicates
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
