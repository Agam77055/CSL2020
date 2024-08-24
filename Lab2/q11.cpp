// This is new year and there is a special game being played at IITJ.                		
// These are the ways how the game is played. 
// 1) There are say  ‘x’ students in the class. Each student is labeled from 1 (first student) to x (last student).
// 2) A paper is given to n-th student.
// 3) The next p-th student who gets the paper quits the game.
// 4) The paper is passed until there is one last student who hasn't left the game.
// 5) The student becomes the class leader.
// Now, your task is to find the number of last student.

// Input
// The first line contains a number T (0 <= T <= 106).
// Each of the next T lines contains 3 integers which are x (0 < x<= 103), n, p (0 < n, p <= x) and are separated by a single space.

// Output
// For each test case, print the required answer.


#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, s, n) for(int i = s; i <= n; i++)

class node {
public:
    int val;
    node* next;
    node(int val = 0, node* next = NULL){
        this->val = val;
        this->next = next;
    }
};


class LinkedList {
public:
    node* head;
    LinkedList(node* head = NULL){
        this->head = head;
    }
    
    
    void clearLL()
    {
        // node* temp = head;
        
        // while (temp != NULL)
        // {
        //     node* temp2 = temp;
        //     temp = temp->next;
            
        //     delete temp2;
        // }
        
        head = NULL;
    }
    
    void studentsList(int x)
    {
        node * tail;
        
        FOR(i, 1, x)
        {
            node *n = new node(i);
            
            if (head == NULL)
            {
                head = n; 
            }
            else
            {
                node* x = head;
                
                while (x->next != NULL)
                {
                    x = x->next;
                }
                
                x->next = n;
            }
            
            if (i == x)
            {
                tail = n;
            }
        }
        
        // connecting the tail back to head because it is a circular linked list
        if (tail != NULL)
        {
            tail->next = head;
        }
    }
    
    void printLL()
    {
        if (head == NULL)
        {
            cout << "EMPTY" << endl;
        }
        else
        {
            node* x = head;
            while(x->next != head)
            {
                cout << x->val << " ";
                x = x->next;
                
                if (x->next->next == head)
                {
                    cout << x->val << " " << x->next->val << " ";
                    break;
                }
            }
        }
        
    }
};

class Game {
private:
    int x; // Number of students
    int n; // Initial student who gets the paper
    int p; // Steps to pass the paper
    LinkedList l;
    
public:

    Game(int x, int n, int p, LinkedList &l) : x(x), n(n), p(p), l(l) {}

    int findwinner() {
        //code here
        
        node* x = l.head;
        
        int count = 1;
        while (count < n)
        {
            x = x->next;
            count++;
            
            // cout << count << " ";
        }
        
        while (x->next != x)
        {
            count = 1;
            
            while (count < p)
            {
                x = x->next;    
                count++;
                // cout << count << " ";
            }
            
            node* temp = x->next;
            x->next = x->next->next;
            
            delete temp;
            
        }
        
        return x->val;
    }
};

int main() {
    int T;
    cin >> T; 
    

    while (T--) {
        int x, n, p;
        cin >> x >> n >> p;
        
        LinkedList list;
        
        // creting a circular linked list
        list.studentsList(x);
        
        // list.printLL();
        
        Game g(x, n, p, list);
        
        cout << g.findwinner() << endl;
        
        list.clearLL();
    }

    return 0;
}
