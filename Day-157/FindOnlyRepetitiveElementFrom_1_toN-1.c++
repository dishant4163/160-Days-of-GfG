// Find Only Repetitive Element from 1 to n-1



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/find-repetitive-element-from-1-to-n-1    



#include<bits/stdc++.h>
using namespace std;



int findDuplicate(vector<int>& arr) {
    // code here
    int n = arr.size(), ans = 0;

    // XOR all numbers from 1 to n-1 & elements in the array
    for(int i = 0; i < n-1; i++) {
        ans = ans ^ (i+1) ^ arr[i];
    }

    // xor the last element in the array
    ans = ans ^ arr[n-1];

    return ans;
}





int main() {

    vector<int> arr = {1, 3, 2, 3, 4};
    cout << "The duplicate element in gievn array is " << findDuplicate(arr);


    return 0;
}
