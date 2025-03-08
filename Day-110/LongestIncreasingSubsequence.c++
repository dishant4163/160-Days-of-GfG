// Longest Increasing Subsequence / LIS


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-increasing-subsequence-1587115620   


#include<bits/stdc++.h>
using namespace std;


// Tabulation Algo
int lis(vector<int>& arr) {
    // code here
    int n = arr.size();
    vector<int> dp(n, 1);

    int maxLen = 1;

    for(int ind = 0; ind < n; ind++) {
        for(int prev = 0; prev < ind; prev++) {
            if(arr[prev] < arr[ind]) {
                dp[ind] = max(dp[ind], 1 + dp[prev]);
            }
        }
        maxLen = max(maxLen, dp[ind]);
    }

    return maxLen;
}


int main() {

    vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    cout << "The output is: " << lis(arr) << endl;


    return 0;
}
