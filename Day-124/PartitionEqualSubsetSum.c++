// Partition Equal Subset Sum / Partition a Set into 2 Equal Subsets of Equal Sum



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/subset-sum-problem2014  



#include<bits/stdc++.h>
using namespace std;


bool equalPartition(vector<int>& arr) {
    //code here
    int n = arr.size(), totalSum = 0;

    for(int i = 0; i < n; i++) totalSum += arr[i];

    if(totalSum % 2 == 1) return false;

    int t = totalSum >> 1;

    vector<vector<bool>> dp(n+1, vector<bool>(t+1, false));

    for(int i = 0; i <= n; i++) dp[i][0] = true;

    for(int ind = 1; ind <= n; ind++) {
        for(int target = 1; target <= t; target++) {
            bool notTake = dp[ind-1][t];
            bool take = false;

            if(arr[ind-1] <= target) {
                take = dp[ind-1][target - arr[ind-1]];
            }

            dp[ind][target] = take || notTake;
        }
    }

    return dp[n][t];
}



int main() {

    vector<int> arr = { 1, 5, 11, 5};
    cout << "The output is: ";
    if (equalPartition(arr)) {
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }


    return 0;
}
