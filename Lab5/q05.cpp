// Consider you are to design a game such that N players in the game can participate initially as they make a cycle. 
// First player could start the game by rolling a dice and get an outcome x. 
// The player at position N%x while traversing the cycle in a clockwise manner would be out in that round (start counting from 
// the person just next to the one who rolled the dice). Whoever gets out in a round, the next person in the line gets to roll the dice. 
// The one player stands at the end of the game is the winner. For each round, print the dice value and player who dropped out. 
// Also print the winner after all the rounds.

// Game Rule Recap:

// Players form a cycle.
// A dice roll (x) determines which player is out.
// The count starts from the player next to the one who rolled the dice.
// The count proceeds clockwise.
// The player at position N%x in the count is out.
// The next player in line rolls the dice for the next round.


// Example:

// Number of Players: 5
// Dice Rolls: 2, 3, 1, 4

// Round 1:
// Player 1 will roll the dice.
// Dice roll: 2
// Count starts from player 2 and will stop at player 3. So, player 3 is out.

// Round 2:
// Player 4 will roll the dice.
// Dice roll: 3
// The count now starts from player 5 and stop at 2. So player 2 is out.

// Round 3:
// Player 4 will roll the dice.
// Dice roll: 1
// The count starts from player 5 and stop at 5 itself. So, player 5 is out.

// Round 4:
// Player 1 will roll the dice.
// Dice roll: 4
// The count starts from player 4 and stop at player 1. So, player 1 is out.

// We are left with player 4.
// The final winner is player 4.

// Output Format:
// For each of the rounds, print the dice value and the player which gets dropped out.
// In the last line, output the winning person.


#include <bits/stdc++.h>

using namespace std;


class Solution{
public:
    void RollingDice(int n,vector<int> diceRolls){
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i+1;
        }

        int current = 0;
        
        for (int j = 0; j < (int) diceRolls.size(); j++)
        {
            n = arr.size();
            
            int i = (current + diceRolls[j] % n) % n;
            
            int remov = arr[i];
            arr.erase(arr.begin() + i);
            
            if (i == arr.size())
            {
                current = 0;
            }
            else
            {
                current = i;
            }
            
            // for (int i = 0; i < arr.size(); i++)
            // {
            //     cout << arr[i] << " ";
            // }
            
            cout << diceRolls[j] << " " << remov << endl;
        }
        
        cout << arr[0] << endl;
    }
};

int main() {
    int n;
    cin>>n;
    
    // The array to store the dice rolls
    vector<int> diceRolls(n - 1);

    // Input dice rolls
    for (int i = 0; i < n - 1; i++) {
        cin>>diceRolls[i];
    }
    
    Solution s;
    s.RollingDice(n,diceRolls);

    return 0;
}
