// Design a program that takes an array of integers as input and sorts it using one of the following sorting algorithms: Bubble Sort, 
// Insertion Sort, or Merge Sort. The program should select the appropriate sorting algorithm based on the size of the input array.

// Criteria for Selecting the Sorting Algorithm:
// Bubble Sort should be used for small datasets (up to 10 elements).
// Insertion Sort should be used for mid-sized datasets (11 to 15 elements).
// Merge Sort should be used for large datasets (more than 15 elements).

// The program should take as input the number of elements in the array followed by the elements of the array. 
// It should output the index of the chosen sorting algorithm and the sorted array.

// Sorting Algorithm Index:
// 1: Bubble Sort
// 2: Insertion Sort
// 3: Merge Sort

// Input Format:
// The first line contains an integer n, the number of elements in the array.
// The second line contains n space-separated integers, representing the elements of the array.
// Output Format:
// The first line should print the index of the sorting algorithm that was used.
// The second line should print the sorted array as space-separated integers.

// Example:
// Input:
// 8
// 34 7 23 32 5 62 32 7
// Output:
// 1
// 5 7 7 23 32 32 34 62


#include <iostream>
#include <vector>
using namespace std;

class SortManager {
private:
    std::vector<int> arr;
    int bth; // Bubble Sort threshold
    int ith; // Insertion Sort threshold
    
    // Function to perform Bubble Sort
    void bubbleSort() {
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - i - 1; j++) 
            {
                if (arr[j] > arr[j + 1]) 
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Function to perform Insertion Sort
    void insertionSort() {
        int n = arr.size();
        
        for (int i = 1; i < n; i++) 
        {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) 
            {
                arr[j + 1] = arr[j];
                j--;
            }
            
            arr[j + 1] = key;
        }
    }
    
    void merge(int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        std::vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for (int i = 0; i < n2; i++) {
            R[i] = arr[m + 1 + i];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Function to perform Merge Sort
    void mergeSort(int l, int r) {
        if (l < r) 
        {
            int m = l + (r - l) / 2;

            mergeSort(l, m);
            mergeSort(m + 1, r);

            merge(l, m, r);
        }
    }

public:
    SortManager(int bubbleThreshold, int insertionThreshold)
        : bth(bubbleThreshold), ith(insertionThreshold) {}

    void getUserInput() {
        int size;
        // std::cout << "Enter the size of the array: ";
        std::cin >> size;
        arr.resize(size);

        // std::cout << "Enter the elements of the array:\n";
        for (int i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
    }

    void printArray() const {
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    void smartSort() {
        int size = arr.size();
        if (size == 0) {
            // std::cout << "Empty array. Nothing to sort." << std::endl;
            return;
        }

        if (size < bth) {
            std::cout << "1" << std::endl;
            bubbleSort();
        } else if (size < ith) {
            std::cout << "2" << std::endl;
            insertionSort();
        } else {
            std::cout << "3" << std::endl;
            mergeSort(0, size - 1);
        }
    }
};

int main() {
    int bubbleThreshold = 10;
    int insertionThreshold = 15;

    SortManager sorter(bubbleThreshold, insertionThreshold);

    sorter.getUserInput();
    sorter.smartSort();
    sorter.printArray();

    return 0;
}
