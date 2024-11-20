// Move all zeros to end of array


// Day-2 Problem Link =>
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/move-all-zeroes-to-end-of-array0751



#include<bits/stdc++.h>
using namespace std;


void pushZerosToEnd(vector<int>& arr) {
    // code here
    int n = arr.size(), j = 0;


    for(int i=0; i < n; i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

}

// Function to print the array (for debugging/validation)
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {


int t;  // Number of test cases
    cin >> t;

    while (t--) {
        int n;  // Size of the array for each test case
        cin >> n;
        
        vector<int> arr(n);

        // Input the array elements
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Call function to push zeros to the end
        pushZerosToEnd(arr);

        // Output the modified array
        printArray(arr);
    }

    return 0;
}