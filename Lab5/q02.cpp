// Implement a program in C++ to process an array (of up to 32 elements) by reversing every alternate group of 3 consecutive digits, 
// while parsing from left to right. The program should repeatedly loop back to the beginning of the array upon reaching the end, 
// but this looping should be limited to 20 repetitions in total. The array should be of variable length (up to 32 elements) and the elements should be input by the user.

// Input:
// User provides the number of elements (up to 32) and then enters the elements of the array. For example, for an 8-size array, the user might input: 3 4 5 6 1 5 7 8.

// Output:
// The program outputs a series where every alternate group of three elements is reversed. The entire series repeats a maximum of 20 times. 
// For the given example input, the output would be: 5 4 3 5 1 6 3 8 7 6 5 4 … (continuing in this pattern for a total of 20 repetitions).


#include <iostream>
#include <vector>
using namespace std;

class ArrayProcessor {
private:
    vector<int> arr; // Vector to hold the array elements
    int n;           // Number of elements in the array
    const int MAX_ITERATIONS = 20; // Maximum number of iterations

    // Function to reverse every group of 3 elements in the vector
    void reverseGroups(vector<int>& vec) {
        for (int i = 0; i < vec.size(); i += 3) {
            int left = i;
            int right = min(i + 2, (int)vec.size() - 1);
            while (left < right) {
                swap(vec[left], vec[right]);
                left++;
                right--;
            }
        }
    }

public:
    // Constructor to initialize the array size and elements
    ArrayProcessor(int size) : n(size) {
        arr.resize(n);
    }

    // Function to input the elements of the array from the user
    void inputArray() {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // Function to process and print the array
    void printProcessedArray() {
        vector<int> extendedArray;

        // Fill the extendedArray with repeated values from arr
        for (int i = 0; i < MAX_ITERATIONS; ++i) {
            for (int j = 0; j < n; ++j) {
                extendedArray.push_back(arr[j]);
            }
        }
        
        if (extendedArray.size() % 3 == 1)
        {
            extendedArray.push_back(arr[0]);
            extendedArray.push_back(arr[1]);
        }
        else if (extendedArray.size() % 3 == 2)
        {
            extendedArray.push_back(arr[0]);
        }
        
        // Reverse every group of 3 elements
        reverseGroups(extendedArray);

        // Output the result
        for (int num : extendedArray) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;

    // Ask the user for the number of elements in the array
    cin >> n;

    // Create an instance of ArrayProcessor
    ArrayProcessor processor(n);

    // Input the array elements
    processor.inputArray();

    // Print the processed array
    processor.printProcessedArray();

    return 0;
}
