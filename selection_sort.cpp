#include <iostream>
#include <vector>
using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Assume the minimum element is the first element
        int minIndex = i;
        // Iterate through the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            // Update minIndex if a smaller element is found
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    
    // Perform Selection Sort
    selectionSort(arr);
    
    // Print the sorted array
    cout << "Sorted array: \n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}