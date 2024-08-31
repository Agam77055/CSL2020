// You are given a double linked list with various functionalities. Your task is to perform different operations on the list based on the provided input. 
// The operations include concatenation of two linked lists, sorting and then concatenating two linked lists, 
// finding the second highest element in the list, and finding pairs in the list with a sum greater than a given value.

// Input Format:
// The first line contains an integer queryType which determines the operation to be performed.
// If queryType == 1, perform simple concatenation of two linked lists.
// If queryType == 2, perform sorted concatenation of two linked lists.
// If queryType == 3, insert the given element in the sorted order in the given sorted doubly linked list.
// If queryType == 4, find the second highest element in a single linked list.
// If queryType == 5, Count the pairs in the list with a sum greater than a given value.
// The second line contains two integers n and m (only for queryType == 1 or queryType == 2), representing the sizes of the two linked lists.
// The third line contains n space-separated integers representing the elements of the first linked list.
// The fourth line contains m space-separated integers representing the elements of the second linked list (only for queryType == 1 or queryType == 2).
// For queryType == 4, the second line contains an integer n, representing the size of the linked list.
// The third line contains n space-separated integers representing the elements of the linked list.
// For queryType == 5, the second line contains two integers n and k, where n is the size of the linked list and k is the target sum.
// The third line contains n space-separated integers representing the elements of the linked list.

// Output Format:
// If queryType == 1, print the elements of the concatenated linked list.
// If queryType == 2, print the elements of the sorted concatenated linked list.
// If queryType == 3, print the elements of the linked list after insertion of given element in sorted order.
// If queryType == 4, print the second highest element in the linked list.
// If queryType == 5, print the count of no of pairs whose sum is strictly greater than the target value k. If no such pair exists, print -1.

// Sample Input:
// 1
// 3 3
// 1 2 3
// 7 8 9
// Sample Output:
// 1 2 3 7 8 9 NULL

// Sample Input:
// 4
// 5
// 4 7 2 6 9
// Sample Output:
// 7

#include<iostream>
#include<climits>

using namespace std;


class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int v = 0, Node* p = nullptr, Node* n = nullptr) {
        data = v;
        prev = p;
        next = n;
    }
};


class DoubleLinkedList {
public:
    Node* head;
    DoubleLinkedList(Node* h = nullptr) {
        head = h;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    void printLinkedList() {
        if (head == nullptr) {
            cout<< "\n";
            return;
        }

        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << "\n";
    }

    
};


DoubleLinkedList concatenate(DoubleLinkedList& old,DoubleLinkedList& other) {
    
    if (old.head == nullptr)
    {
        old.head = other.head;
        return old;
    }
    
    Node* x = old.head;
    
    while (x->next != nullptr)
    {
        x = x->next;
    }
    
    x->next = other.head;
    if (other.head != nullptr)
    {
        other.head->prev = x;
    }
    
    return old;
}


DoubleLinkedList sortedConcatenate(DoubleLinkedList& l1, DoubleLinkedList& l2) {
    DoubleLinkedList newHead;
    Node* z = nullptr;
    
    Node* x = l1.head;
    Node* y = l2.head;
    
    if (x != nullptr && (y == nullptr || x->data <= y->data))
    {
        newHead.head = x;
        z = x;
        x = x->next;
    }
    else if (y != nullptr)
    {
        newHead.head = y;
        z = y;
        y = y->next;
    }
    
    while (x != nullptr && y != nullptr)
    {
        if (x->data <= y->data)
        {
            z->next = x;
            x->prev = z;
            z = x;
            
            x = x->next;
        }
        else
        {
            z->next = y;
            y->prev = z;
            z = y;
            
            y = y->next;
        }
    }
    
    while (x != nullptr)
    {
        z->next = x;
        x->prev = z;
        z = x;
        
        x = x->next;
    }
    
    while (y != nullptr)
    {
        z->next = y;
        y->prev = z;
        z = y;
        
        y = y->next;
    }

    return newHead;
}


DoubleLinkedList insertSorted(DoubleLinkedList& l, int val) {
    Node* x = l.head;
    Node* newNode = new Node(val);
    
    if (x == nullptr || x->data >= val)
    {
        newNode->next = x;
        if (x != nullptr)
        {
            x->prev = newNode;
        }
        
        l.head = newNode;
        return l;
    }
    
    while (x->next != nullptr && x->next->data < val)
    {
        x = x->next;
    }
    
    newNode->next = x->next;
    if (x->next != nullptr)
    {
        x->next->prev = newNode;
    }
    
    x->next = newNode;
    newNode->prev = x;
    
    return l;
    
}

int secondHighest(DoubleLinkedList& l) {
    if(l.head == nullptr || l.head->next == nullptr)
    {
        return -1;
    }
    
    Node* x = l.head;
    
    int max = INT_MIN;
    int smax = INT_MIN;
    
    while (x != nullptr)
    {
        if (x->data >= max)
        {
            smax = max;
            max = x->data;
        }
        else if (x->data > smax && x->data < max)
        {
            smax = x->data;
        }
        
        x = x->next;
    }
    
    if (smax == INT_MIN) return -1;
    return smax;
}

void pairSumGreaterThanX(DoubleLinkedList& l, int x) {
    Node* n = l.head;
    int count = 0;
    
    if (l.head == nullptr || l.head->next == nullptr)
    {
        cout << -1 << endl;
        return;
    }
    
    while (n!= nullptr)
    {
        Node* n2 = n->next;
        while (n2 != nullptr)
        {
            if (n->data + n2->data > x) count++;
            n2 = n2->next;
        }
        
        n = n->next;
    }
    
    if (count == 0)
    {
        cout<<-1<<endl;
        return;
    }
    
    cout << count << endl;
}

int main(){

    int queryType;
    cin>>queryType;
    if(queryType==1){
        int n,m;
        cin>>n>>m;
        DoubleLinkedList list1;
        DoubleLinkedList list2;
        int x;
        while (n--)
        {
            cin>>x;
            list1.insert(x);
        }
        while (m--)
        {
            cin>>x;
            list2.insert(x);
        }
        concatenate(list1,list2).printLinkedList();
        
    }

    else if (queryType==2)
    {
        int n,m;
        cin>>n>>m;
        DoubleLinkedList list1;
        DoubleLinkedList list2;
        int x;
        while (n--)
        {
            cin>>x;
            list1.insert(x);
        }
        while (m--)
        {
            cin>>x;
            list2.insert(x);
        }
        sortedConcatenate(list1,list2).printLinkedList();
    }
    else if (queryType==3)
    {
        int n;
        cin>>n;
        int x;
        DoubleLinkedList list1;
        while (n--)
        {
            cin>>x;
            list1.insert(x);
        }
        int k;
        cin>>k;
        insertSorted(list1,k).printLinkedList();
    }
    
    else if (queryType==4)
    {
        int n;
        cin>>n;
        DoubleLinkedList list1;
        int x;
        while (n--)
        {
            cin>>x;
            list1.insert(x);
        }
        cout << secondHighest(list1) << endl;
        
    }
    else if (queryType==5)
    {
        int n,k;
        cin>>n>>k;
        DoubleLinkedList list1;
        int x;
        while (n--)
        {
            cin>>x;
            list1.insert(x);
        }
        pairSumGreaterThanX(list1,k);
    }
    
    return 0;
}
