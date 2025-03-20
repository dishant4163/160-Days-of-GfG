// Minimum Jump/Jump Game (minimum jumps to reach end)


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/minimum-number-of-jumps-1587115620   



#include<bits/stdc++.h>
using namespace std;


int minJumps(vector<int>& arr) {
    // code here
    int n = arr.size();

    vector<int> dp(n, INT_MAX);

    dp[n-1] = 0;

    for(int i = n-2; i >= 0; i--) {
        for(int j = i+1; j <= i + arr[i] && j < n; j++) {
            if(dp[j] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
    }

    if(dp[0] == INT_MAX) return -1;

    return dp[0];
}



int main() {

    vector<int> arr = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    cout << "The output is: " << minJumps(arr);


    return 0;
}
