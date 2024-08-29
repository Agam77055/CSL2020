// You are provided with a list of integers representing a series of asteroids aligned in a row. 
// The absolute value of each integer indicates the size of the asteroid, while the sign denotes its direction 
// (a positive sign signifies movement to the right, and a negative sign to the left). All asteroids travel at the same speed.

// Your task is to determine the final arrangement of the asteroids after all possible collisions have occurred. 
// When two asteroids collide, the smaller one is destroyed. If they are of equal size, both are destroyed. 
// Asteroids moving in the same direction will never collide.

// Input Format : 
// First line of the input contains an integer n representing the total number of asteroids.
// Second line contains n integers, representing current state of the moving asteroids. 
// (Positive indicates coin moving from left to right and negative indicates coins moving from right to left.)

// Output Format : 
// Print the final state of the asteroids after all possible collisions have occurred.
// (Print nothing if all asteroids are removed)
// Output should contain space separated integers.


// Example Input : 
// 3
// 5 10 -5

// Example Output :
// 5 10
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.


#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)

class Stack {
public:
    vector<int> elements;
    
    void push(int value) {
        elements.push_back(value);
    }

    void pop() {
        elements.pop_back();
    }

    int top() const {
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }
};

class Collisions {
private:
    vector<int> arr;
    Stack stack;

public:
    Collisions(vector<int>& arr) {
        this->arr = arr;
    }

    vector<int> solve() {
        // Complete this solve function to find the final state of the asteroids after all possible collisions.
        
        FOR(i, (int) arr.size())
        {
            int flag = 1;
            
            while (flag == 1 && !stack.empty() && arr[i] < 0 && stack.top() > 0)
            {
                if (stack.top() == -arr[i])
                {
                    stack.pop();
                    flag = 0;
                }
                else if (stack.top() > -arr[i])
                {
                    flag = 0;
                }
                else
                {
                    stack.pop();
                }
            }
            
            if (flag == 1)
            {
                stack.push(arr[i]);
            }
        }
        
        return stack.elements;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Collisions collide(arr);
    vector<int> result = collide.solve();

    for (int value : result) {
        cout << value << " ";
    }
    
    return 0;
}
