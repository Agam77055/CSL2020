// Design a LRUCache data structure
// First, initialize the LRU cache with positive size capacity = n.
// Then we perform a certain number of 'get' and 'put' operations = numOps
// int get(int key) returns the value of the key if the key exists, otherwise return -1.
// Void put(int key, int value), Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, remove the least recently used key and then add the new key-value pair.
// Both get and put can be implemented in O(n).
// In input:
// '1 x' denotes perform get(x) operation.
// '2 x y' denotes perform put(x,y) operation.

// Input format:
// Size of cache = n, then number of operations = numOps
// Followed by all 'numOps' operations

// Example:
// Input:
// 2 10
// 2 1 10
// 2 1 100
// 2 2 20 
// 1 1
// 2 3 30
// 1 2
// 2 4 40
// 1 1
// 1 3
// 1 4
// Output:
// 100
// -1
// -1
// 30
// 40

// Explanation:
// First make a cache of size 2 { _, _ }
// Now we perform 10 operations:
// put(1, 10) --> cache contains {1:10, _ }
// put(1, 100) --> cache contains {1:100, _ }
// put(2, 20) --> cache contains {1:100, 2:20}
// get(1) --> return 10
// put(3, 30) --> No space, so remove key 2 as it was LRU, cache contains {1:100, 3:30}
// get(2) --> returns -1 (not found)
// put(4, 40) -->  No space, so remove key 1 as it was LRU, cache contains {4:40, 3:30}
// get(1) --> return -1 (not found)
// get(3) --> return 30
// get(4) --> return 40

#include <iostream>

class LRUCache{
    public:
    
    class Node{
        public:
        int key;
        int value;
        Node* next;
        Node* prev;
        
        Node(): key(0), value(0), next(nullptr), prev(nullptr) {};
        Node(int x, int y): key(x), value(y), next(nullptr), prev(nullptr) {};
        
    };
    
    Node *head;
    Node *tail;
    int maxsize;
    int size;
    
    LRUCache(int x): head(nullptr), tail(nullptr), maxsize(x), size(0) {};
    
    void enqueue(int x, int y)
    {
        Node *newNode = new Node(x,y);
        if(head==nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    
    int isEmpty(){
        return (head==nullptr);
    }
    
    int dequeue(){
        if (isEmpty()) {std::cout << "Stack underflow" << std::endl ; exit(EXIT_FAILURE); }
        Node* popped = tail;
        int val = popped->key;
        tail = tail->prev;
        tail->next = nullptr;
        delete popped;
        size--;
        return val;
    }
    

    // implement any other supporting methods here
    
    int get(int x){
        // implement your get method here
    }
    
    void put(int x, int y)
    {
        // implement your put method here
        return;
    }
};

int main(){
    int n, numOps, op, num1, num2;
    std::cin >> n >> numOps;
    LRUCache cache(n);
    
    for(;numOps;numOps--)
    {
        std::cin >> op;
        if(op == 1)
        {
            std::cin >> num1;
            std::cout << cache.get(num1) << std::endl;
        }
        else
        {
            std::cin >> num1 >> num2;
            cache.put(num1,num2);
        }
    }
    return 0;
}
