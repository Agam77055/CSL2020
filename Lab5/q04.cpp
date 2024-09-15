// Given an unsorted list of integers (size > 100000), print all sub list whenever there is an occurrence of same digit is separated by at most 1 place apart. 

// For example, 22 or 101 will be printed, as 2 is occuring just after 2 , and 1 is occuring just after 1 other digit . but  4564 or 28912 will not be printed . 

// Create the initial list of integers by calling the random function. 

// Input: 56278991719100035615….
// Output: 99, 171, 191, 00, 000, 00, …


#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class SubListFinder {
public:
    SubListFinder(const T* arr) : arr(arr), n(strlen(arr)) {}

    void findSublists() const {
        for (int i = 0; i < n; i++)
        {
            if (i != n-1 && arr[i] == arr[i+1])
            {
                cout << arr[i] << arr[i+1] << ", ";
            }
            
            if (i != n-2 && arr[i] == arr[i+2])
            {
                cout << arr[i] << arr[i+1] << arr[i+2] << ", ";
            }
        }
    }

private:
    const T* arr;
    int n;
};

int main() {
    char input[100001]; 
    cin >> input;
    SubListFinder<char> finder(input);
    finder.findSublists();

    return 0;
}
