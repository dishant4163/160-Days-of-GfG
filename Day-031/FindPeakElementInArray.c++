// Find Peak Element in Array


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/peak-element   


#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr) {
    int n = arr.size();

    if(n == 1) return 0;

    if(arr[0] > arr[1]) return 0;

    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n-2;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;

        if(arr[mid] < arr[mid + 1]) low = mid + 1;
        else high = mid - 1;
    }

    return 0;
}



int main() {

    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};
    cout << "The index at which peak element exits is : " << peakElement(arr) << endl;


    return 0;
}
