// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // For std::reverse
using namespace std;

// Template class to handle the removal of k digits
class KDigitsRemover {
public:
    // Constructor to initialize the number and the count of digits to remove
    KDigitsRemover(const std::string& number, int removeCount)
        : num(number), k(removeCount) {}

    // Public method to perform the removal of k digits
    string removeKdigits() {
        string x = num;
        // reverse(x.begin(), x.end());
        
        stack<char> st;
        
        for(int i = 0; i < (int) x.size(); i++)
        {
            char c = x[i];
            
            while (!st.empty() && k > 0 && st.top() > c)
            {
                st.pop();
                k--;
            }
            
            st.push(c);
        }
        
        while (!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }
        
        string smallNumber;
        
        while(!st.empty())
        {
            smallNumber = st.top() + smallNumber;
            st.pop();
        }
        
        while (smallNumber.size() > 1 && smallNumber[0] == '0')
        {
            smallNumber.erase(smallNumber.begin());
        }
        
        if (!smallNumber.empty())
        {
            return smallNumber;
        }
        
    }

private:
    std::string num; // Number as a string
    int k;           // Number of digits to remove
};

int main() {
    std::string num;
    int k;

    // Input handling
    std::cin >> num;
    std::cin >> k;

    // Create an instance of KDigitsRemover
    KDigitsRemover remover(num, k);

    // Call the method to get the smallest number
    std::string smallestNumber = remover.removeKdigits();

    // Output the result
    std::cout << smallestNumber << std::endl;

    return 0;
}
