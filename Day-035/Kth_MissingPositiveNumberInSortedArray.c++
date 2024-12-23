// K-th Positive Missing Number in Sorted Array


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/kth-missing-positive-number-in-a-sorted-array    

#include<bits/stdc++.h>
using namespace std;

int kthMissing(vector<int> &arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int missingNum = arr[mid] - (mid + 1);

        if(missingNum < k) low = mid + 1;
        else high = mid - 1;
    }

    return (low + k); // or return (k + high+1)
}


int main() {

    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "The missing +ve number is: " << kthMissing(arr, k);


    return 0;
}