// Unique Number 1


// Problem Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/find-unique-number



#include<bits/stdc++.h>
using namespace std;



int findUnique(vector<int>& arr) {
    // Code here
    int n = arr.size(), xorr = 0;

    for(int i=0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }

    return xorr;
}



int main() {

    vector<int> arr = { 2, 3, 5, 4, 5, 3, 4 };
    cout << "The unique number is " << findUnique(arr) << endl;


    return 0;
}