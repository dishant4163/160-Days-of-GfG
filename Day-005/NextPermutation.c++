// Next Permutation

//Problem Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/next-permutation5226 


#include<bits/stdc++.h>
using namespace std;


void nextPermutation(vector<int>& arr) {
    int n = arr.size(), pivotIndex = -1;

    // Step 1: Find the first element that is smaller than the next element (pivot)
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivotIndex = i;
            break;
        }
    }

    // If there is no such element, reverse the entire array
    if (pivotIndex == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    // Step 2: Find the element just larger than arr[pivotIndex] and swap them
    for (int i = n - 1; i > pivotIndex; i--) {
        if (arr[i] > arr[pivotIndex]) {
            swap(arr[i], arr[pivotIndex]);
            break;
        }
    }

    // Step 3: Reverse the elements after the pivot index
    reverse(arr.begin() + pivotIndex + 1, arr.end());
}

int main() {
    // Input array (change this to test with different inputs)
    vector<int> arr = {1, 2, 3};

    // Output the array before next permutation
    cout << "Before nextPermutation: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Call the nextPermutation function
    nextPermutation(arr);

    // Output the array after next permutation
    cout << "After nextPermutation: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

