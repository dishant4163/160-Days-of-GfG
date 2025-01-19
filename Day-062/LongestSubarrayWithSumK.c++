// Longest Subarray With Sum K


// Problem-Link->   
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/longest-sub-array-with-sum-k0809


#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    // code here
    int n = arr.size(), maxLen = 0, sum = 0;
    unordered_map<int, int> preSumMp;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == k) {
            maxLen = max(maxLen, i+1);
        }

        int remainSum = sum - k;

        if(preSumMp.find(remainSum) != preSumMp.end()) {
            int len = i - preSumMp[remainSum];
            maxLen = max(maxLen, len);
        }

        if(preSumMp.find(sum) == preSumMp.end()) {
            preSumMp[sum] = i;
        }
    }

    return maxLen;
}


int main() {

    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << "The length of Longest Subarray With Sum" << k << " is: " << longestSubarray(arr, k) << endl;


    return 0;
}
