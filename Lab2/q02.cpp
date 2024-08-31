// Kavya had some "postfix summation expressions", with natural numbers stored in her summer math project data. Unfortunately, due to data corruption, 
// only information about whether there is a number or a symbol at odd positions remained visible, i.e., for each odd position, only the information whether 
// there is a number there or operator sign there was available. 

// For e.g., the postfix expression "1 2 4 + - 3 +" became "x x o o" after corruption, where x denotes presence of number, and o denotes presence of an operator.
// Kavya has managed to recover the order of numbers occurring in the expression as well as the order of operators,
// but she does not know the location where the numbers and operators need to be placed. For e.g., for the expression "1 2 4 + - 3 +", 
// she has recovered the number sequence "1 2 4 3", and the operator sequence "+ - +", but does not know their location in the expression.
// Given the corrupted data, can you help her obtain the variable and operator positions?
// Since multiple expressions are possible for any given data, she wants to guess the expression with "earlier variables operated first" as the solution. 
// (e.g. given below)

// Input:
// Number of numbers in the expression 'n'
// The information sequence of symbol vs number (x denotes number, o denotes operator)
// Output:
// The postfix expression (It is guaranteed that there is at least one possible expression with given rules for given input)

// E.g.1:
// Input:
// 3
// x x o
// Output:
// x1 x2 x3 o1 o2

// E.g.2:
// Input:
// 4
// x x o o
// Output:
// x1 x2 x3 o1 o2 x4 o3

// Explanation 1:
// The expression is "x _ x _ o", where _ represents the missing data. 
// The only possible way to make this a valid postfix expression is by placing a number and operator in the empty positions respectively, 
// turning the expression to: "x1 x2 x3 o1 o2".

// Explanation 2:
// Here, for "x _ x _ o _ o", we can form " x1 x2 x3 o1 o2 x4 o3 " or " x1 x2 x3 x4 o1 o2 o3 " as valid postfix expressions. 
// However, the first gives "(x1 o2 (x2 o1 x3)) o3 x4" in infix notation, while the second combination gives "x1 o3 (x2 o2 (x3 o1 x4))" in infix notation, 
// which means in the first expression, x2 and x3 are operated on first, while in second expression, x3 and x4 are operated on first.
// Since x2 precedes x4, by the "earlier variables operated first" rule, the first expression is the answer.


#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        Node *next;
        Node(char value): data(value), next(nullptr) {}
};

class LinkedList{
    public:
        
        int size;
        Node *root;
        
        LinkedList(){
            root = nullptr;
            size = 0;
        }
        
        // ~LinkedList() {
        //     Node* current = root;
        //     while (current != nullptr) {
        //         Node* nextNode = current->next;
        //         delete current;
        //         current = nextNode;
        //     }
        // }
        
        void enqueue(char value){
            Node* newNode = new Node(value);
            if(root == nullptr){
                root = newNode;
                root->next = root;
            }
            else{
                newNode->next = root->next;
                root->next = newNode;
                root = newNode;
            }
            size += 1;
        }
        
        void dequeue(){
            if (root == nullptr) return;
            if(root->next == root) delete root;
            else{
                Node *deleted = root->next;
                root->next = deleted->next;
                delete deleted;
            }
            size--;
        };
        
        void traverse(){
            Node *ptr = root;
            int count1 = 1;
            int count2 = 1;
            while (ptr != nullptr)
            {
                if (ptr->data == 'x')
                {
                    cout << ptr->data << count1 << " ";
                    count1++;
                }
                else
                {
                    cout << ptr->data << count2 << " ";
                    count2++;
                }
                ptr = ptr->next;
            }
            cout<<endl;
        };
        
        void solution(){
            // Write your main solution code here
            
            int count1 = 1;
            int count2 = 1;
            
            int iter = 1;
            
            Node* n = root->next;
            int nos = 0;
            
            int totalSize = 2*size - 1;
            
            while (totalSize > 0)
            {
                if (iter % 2 == 1)
                {
                    if (n->data == 'x')
                    {
                        cout << 'x' << count1++ << " ";
                        nos++;
                        n = n->next;
                    }
                    else
                    {
                        cout << 'o' << count2++ << " ";
                        nos--;
                        n = n->next;
                    }
                }
                else
                {
                    if (nos >= 2)
                    {
                        cout << 'o' << count2++ << " ";
                        nos--;
                    }
                    else
                    {
                        cout << 'x' << count1++ << " ";
                        nos++;
                    }
                }
                
                iter++;
                totalSize--;
            }
        
        }
};

int main(){
    LinkedList L;
    int size;
    cin >> size;
    // Input size and expression here
    for (int i = 0; i < size; i++)
    {
        char c;
        cin>>c;
        
        L.enqueue(c);
    }
    
    L.solution();
    
    return 0;
}
