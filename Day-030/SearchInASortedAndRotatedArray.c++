// Search in a Sorted and Rotated Array


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/search-in-a-rotated-array4618  


#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;

    while(low <= high) {
        int mid =  low + (high - low) / 2;

        if(arr[mid] == key) return mid;

        if(arr[mid] >= arr[low]) {
            if(key >= arr[low] && key < arr[mid]) high = mid - 1;
            else low = mid + 1;
        }
        else {
            if(key > arr[mid] && key <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }

    return -1;
}


int main() {

    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    cout << "The Key found at index " << search(arr, key) << endl;


    return 0;
}

