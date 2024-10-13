// Alice and Bob use a sequence of numbers (a1,a2,…,an) to play a game. Alice goes first, with Alice and Bob taking alternate turns. 
// Alice wants to maximize the value of a1 in the end, while Bob wants to minimize the value of a1  in the end.

// Game Rules : 
// 1. The game is over when there is only one element left in the sequence.
// 2. When Alice takes the turn and the game is still in progress, she chooses an index i such that 1 <= i <= m-1 (where m is sequence's current length), 
// updates a_{i} to max(a_{i}, a_{i+1}) and eliminates a_{i+1}. 
// 3. When Bob takes over, he selects an index i under the identical circumstances, he eliminates a_{i+1} and updates a_{i} to min(a_{i},a_{i+1}). 


// Find the value of a1 in the end if both Alice and Bob play optimally. 


// INPUT FORMAT : 
// The first line contains the number of test cases t (1 <= t <= 10,000). Each test case is as follows :
// 1. The first line of each test case contains a single integer n (2 <= n <= 1,00,000) which is the length of the sequence. 
// 2. The second line of each test case contains n integer a1, a2, a3, ... , an (1 <= ai <= 1,00,000). 


// OUTPUT FORMAT : 
// 1. For each test case, output a single integer which is the value of a1 in the end if both players play optimally. 


// EXAMPLE : 
// INPUT 
// 1
// 5
// 3 1 2 2 3

// OUTPUT 
// 2

// EXPLANATION
// At the beginning of the game, the sequence is a = [3, 1, 2, 2, 3].
// 1. Alice starts and selects i = 4. She sets a4 to max(a4, a5) = 3, removes a5, and the sequence becomes [3, 1, 2, 3].
// 2. Bob then chooses i = 3, sets a3 to min(a3, a4) = 2 , removes a4, and the sequence is now [3, 1, 2].
// 3. Alice chooses i = 2, sets a2 to max(a2, a3) = 2, removes a3, and the sequence reduces to [3, 2].
// 4. Finally, Bob selects i = 1, sets a1 to min(a1, a2) = 2, removes a2, leaving the final sequence as [2] .


#include <bits/stdc++.h>
using namespace std;

class AliceAndBobTwo {
public:
    vector<int> gameSolver(vector<int> &arr, int n, int count) {
        // Add your code here
        if (n == 1) return arr;
        
        
        if (count == 0)
        {
            int min = arr[0];
            int index = 0;
            
            for (int i = 1; i < n; i++)
            {
                if (min >= arr[i])
                {
                    min = arr[i];
                    index = i;
                }
            }
            
            arr.erase(arr.begin() + index);
            
            gameSolver(arr, n-1, 1);
        }
        else
        {
            int max = arr[0];
            int index = 0;
            
            for (int i = 1; i < n; i++)
            {
                if (max <= arr[i])
                {
                    max = arr[i];
                    index = i;
                }
            }
            
            arr.erase(arr.begin() + index);
            
            gameSolver(arr, n-1, 0);
        }
        
        return arr;
    }
};

int main() {
     // Add your code here
    int t;
    cin>>t;
    
    while (t--)
    {
        int n;
        cin>>n;
        
        vector<int> arr;
        
        for (int i = 0; i < n; i++)
        {
            int num;
            cin>>num;
            
            arr.push_back(num);
        }
        
        AliceAndBobTwo ab;
        
        arr = ab.gameSolver(arr, n, 0);
        
        cout << arr[0] << endl;
    }
    
    return 0;
}
