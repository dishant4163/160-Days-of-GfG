// Count Number Of Occurrences in a Sorted Array


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/number-of-occurrence2259   


#include<bits/stdc++.h>
using namespace std;

// function for Lower Bound
int lB(vector<int>& arr, int x) {
    int ans = arr.size();
    int low = 0, high = arr.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

// function for Upper Bound
int uB(vector<int>& arr, int x) {
    int ans = arr.size();
    int low = 0, high = arr.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int countFreq(vector<int> &arr, int target) {
    // Count Number Of Occurrences UpperBound - LowerBound
    return uB(arr, target) - lB(arr, target);
}


int main() {

    vector<int> arr = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int target = 2;
    cout << "Number of Occurrences is: " << countFreq(arr, target);


    return 0;
}