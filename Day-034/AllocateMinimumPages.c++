// Allocate Minimum Pages


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/allocate-minimum-number-of-pages0937   


#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& arr, int pages) {
    int cntStudents = 1, pageSum = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(pageSum + arr[i] > pages) {
            cntStudents++;
            pageSum = arr[i];
        } else {
            pageSum += arr[i];
        }
    }

    return cntStudents;
}

// main function
int findPages(vector<int> &arr, int k) {
    if(k > arr.size()) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if (countStudents(arr, mid) > k) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}



int main() {

    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << "The output is: " << findPages(arr, k);



    return 0;
}