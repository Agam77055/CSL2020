// Given two lists, write functions to sort one in ascending order and the other in descending order and then merge two sorted lists 
// in an alternating fashion (start with the first list), until one list is depleted, at which point print the remaining elements of the other list.

// Inputs: 
// 7
// 5 6 7 2 9 4 3
// 9
// 3 7 1 4 2 9 8 1 5

// Outcome: 2 9 3 8 4 7 5 5 6 4 7 3 9 2 1 1 

// Explanation: Sorting the lists in ascending and descending order gives:
// 1st list: 2 3 4 5 6 7 9
// 2nd list: 9 8 7 5 4 3 2 1 1 
// Alternatingly printing the members gives 2 9 3 8 4 7 5 5 6 4 7 3 9 2, at which point the first list gets depleted,
// so you just continue printing the remaining of the 2nd list, which are 1 1.


#include <bits/stdc++.h>

using namespace std;

class ArrayOperations {
private:
    vector<int> *arr1, *arr2;

public:
    // Constructor to initialize arrays
    ArrayOperations(vector<int> &a1, vector<int> &a2) {
        arr1 = &a1;
        arr2 = &a2;
    }

    // Function to merge the arrays alternately and print the result
    void SortNalternatingMerge() {
        sort(arr1->begin(), arr1->end());
        sort(arr2->rbegin(), arr2->rend());
        
        int n = max(arr1->size(), arr2->size());
        
        vector<int> ans;
        
        for (int i = 0; i < n; i++)
        {
            if (i >= (int) arr1->size())
            {
                ans.push_back((*arr2)[i]);
                continue;
            }
            else if (i >= (int) arr2->size())
            {
                ans.push_back((*arr1)[i]);
                continue;
            }
            
            ans.push_back((*arr1)[i]);
            ans.push_back((*arr2)[i]);
        }
        
        for (int i: ans) cout << i << " ";
    }
};

int main() {
    int n1, n2;

    // Reading the size and elements of the first array
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Reading the size and elements of the second array
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Creating an object of ArrayOperations
    ArrayOperations arrayOps(arr1, arr2);

    // Sorting and Merging and printing the arrays
    arrayOps.SortNalternatingMerge();

    return 0;
}
