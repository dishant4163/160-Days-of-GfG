// Count Inversion of an Array

// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/inversion-of-array-1587115620

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1, cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = low + (high - low) / 2;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);

    return cnt;
}
// Function to count inversions in the array.
int inversionCount(vector<int> &arr) {
    // Your Code Here
    int n = arr.size();

    return mergeSort(arr, 0, n - 1);
}

int main() {

    vector<int> arr = {4, 3, 2, 1};
    cout << "The Output is: " << inversionCount(arr);


    return 0;
}
