// Minimum in a Sorted and Rotated Array


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/minimum-element-in-a-sorted-and-rotated-array3611  


#include<bits/stdc++.h>
using namespace std;

int findMini(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while(low < high) {
        if(arr[low] < arr[high])
            return arr[low];

        int mid = low + (high - low) / 2;

        if(arr[mid] > arr[high]) low = mid+1;
        else high = mid;
    }

    return arr[low];
}


int main() {

    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    cout << "The minimum Element in Sorted & Rotated Array is: " << findMini(arr) << endl;


    return 0;
}