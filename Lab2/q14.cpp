// Write a program to flip a segment of a singly linked list. A head will be given and two integers that will denote two indices in the list. 
// Now, do the following as shown:

// Input list: 1->2->3->4->5->6->7  And 3,6

// Output list: 1->2->6->5->4->3->7

#include <iostream>
using namespace std;
struct ListNode {
    int value;
    ListNode *next;
    ListNode(int val) : value(val), next(nullptr) {}
};

void printList(ListNode *head) {
    ListNode *temp = head;
    while (temp) {
        cout << temp->value;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}


ListNode* reverseSegment(ListNode *head, int left, int right) {
   /// code here
   
   //      ***SOLUTION 1***
   
    // ListNode* dummy = new ListNode(0);
    // dummy->next = head;
    // ListNode* x = dummy;;

    // ListNode* temp1 = nullptr;
    // ListNode* temp2 = nullptr;
    // ListNode* temp3 = nullptr;
    
    // // int flag = 0;
    
    // while (x != nullptr)
    // {
    //     if (x->next != nullptr && x->next->value == left)
    //     {
    //         temp1 = x;
    //         temp2 = temp1->next;
    //     }
        
    //     if (x->value == right)
    //     {
    //         temp3 = x;
    //     }
        
    //     x = x->next;
    // }
    
    // // cout << temp1->value << endl;
    
    // if (temp1 == nullptr || temp2 == nullptr || temp3 == nullptr)
    // {
    //     return head;
    // }
    
    // x = temp2;
    // ListNode* prev = nullptr;
    
    // while (x != temp3)
    // {
    //     ListNode* next = x->next;
    //     x->next = prev;
    //     prev = x;
    //     x = next;
    // }
    
    // temp1->next = temp3;
    // temp2->next = temp3->next;
    // temp3->next = prev;
    
    // head = dummy->next;
    // delete dummy;
    
    // return head;
    
    //    *** SOLUTION 2 ***
    
    // if (!head) return nullptr;
    
    // ListNode* dummy = new ListNode(0);
    // dummy->next = head;
    // ListNode* bleft = dummy;
    
    // while (bleft != nullptr && bleft->next->value != left)
    // {
    //     bleft = bleft->next;
    // }
    
    // if (!bleft->next) return head;
    
    // ListNode* leftn = bleft->next;
    // ListNode* rightn = leftn;
    // ListNode* aright = leftn->next;
    
    // while(aright != nullptr && rightn->value != right)
    // {
    //     ListNode* temp = aright->next;
    //     aright->next = rightn;
    //     rightn = aright;
    //     aright = temp;
    // }
    
    // bleft->next = rightn;
    // leftn->next = aright;
    
    // head = dummy->next;
    // delete dummy;
    
    // return head;
    

    //   *** SOLUTION 3 ***
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    int count = 1;

    while (count < left) {
        prev = prev->next;
        count++;
    }

    ListNode* current = prev->next;
    ListNode* next = nullptr;

    while (count < right) {
        next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
        count++;
    }

    head = dummy->next;
    delete dummy;
    return head;

}

int main() {
    
    int value;
    ListNode *head = nullptr, *tail = nullptr;
    
    // inputing the values of the LL
    while (cin >> value) {
        if (value == -1) break;
        ListNode *newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Inputing the values of elements to swap
    int left, right;
    cin >> left >> right;
    
    // printing the original LL
    cout << "Original list: ";
    printList(head);
    head = reverseSegment(head, left, right);
    
    // printing the new LL
    cout << "Modified list: ";
    printList(head);
    
    // deleting the LL
    ListNode *temp;

    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
