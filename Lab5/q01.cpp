// Given are two non-empty linked lists representing non-negative integers. The digits in each linked list are stored in reverse order,
// and each node holds a single digit. Your task is to add the two numbers represented by these linked lists and return the result as a new linked list.

// It can be assumed that the two numbers do not have any leading zeros, except when the number itself is 0.

// Input: l1 = 125 (stored as [5, 2, 1]) and l2 = 243 (stored as [3, 4, 2]).
// Output:  863
// Explanation: The sum of these two numbers is 368 (equivalent to [8, 6, 3]). The linked lists are stored in reverse order, 
// and the result is obtained by adding the numbers in this order.

// Input: l1 = 123 (stored as [3, 2, 1]) and l2 = 0 (stored as [0]).
// Output:  321
// Explanation: The sum of these two numbers is 123 (equivalent to [3, 2, 1])

// Input: l1 = 2457 (stored as [7, 5, 4, 2]) and l2 = 263 (stored as [3, 6, 2]).
// Output:  0272
// Explanation: The sum of these two numbers is 2720 (equivalent to [0, 2, 7, 2])


#include <iostream>
#include <vector>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;
    
    Node(): next(nullptr) {}
    Node(int val): data(val), next(nullptr) {}
};

// Class to represent a linked list
class LinkedList {
public:
    Node* head = nullptr;
    int size = 0;
    
    void create(int num)
    {
        while (num > 0)
        {
            Node* n = new Node(num % 10);
            num /= 10;
            size++;
            
            if(!head) head = n;
            else
            {
                Node* x = head;
                while (x->next)
                {
                    x = x->next;
                }
                
                x->next = n;
            }
            
        }
    }
    

    // Function to add two linked lists representing numbers
    LinkedList add_two_numbers(LinkedList list, int s)
    {
        LinkedList newLL;

        Node* curr = nullptr;
        Node* x = head;
        Node* y = list.head;
        int carry = 0;
        
        while (x || y || carry)
        {
            int sum = carry;
            if (x)
            {
                sum += x->data;
                x = x->next;
            }
            
            if (y)
            {
                sum += y->data;
                y = y->next;
            }
            
            Node* currdat = new Node(sum % 10);
            carry = sum / 10;
            // cout << currdat->data << " ";
            
            if (!newLL.head)
            {
                newLL.head = currdat;
                curr = newLL.head;
            }
            else
            { 
                curr->next = currdat;
                curr = curr->next;
            }
        }
        
        // cout << newLL.head->next->data << " ";
        return newLL;
    }

    // Function to display the linked list
    void print_list() 
    {
        Node* x = head;
        vector<int> arr;
        
        while (x)
        {
            arr.push_back(x->data);
            // cout << x->data << " ";
            x = x->next;
        }
        
        for (int i = 0; i < (int) arr.size(); i++)
        {
            cout << arr[i];
        }
        
        cout << endl;
    }

};

int main() {
    int num1, num2;

    // Input for two numbers
    cin >> num1 >> num2;

    // Creating linked lists for the input numbers
    LinkedList list1, list2;
    
    list1.create(num1);
    list2.create(num2);
    
    // list1.print_list();
    // list2.print_list();

    // Adding the linked lists
    LinkedList result = list1.add_two_numbers(list2, max(list1.size, list2.size));

    // Displaying the result
    result.print_list();

    return 0;
}
