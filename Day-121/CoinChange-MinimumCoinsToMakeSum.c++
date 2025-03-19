// Coin Change - Minimum To Make Sum


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/number-of-coins1824  


#include<bits/stdc++.h>
using namespace std;


// Function to find the minimum number of 
// coins needed to make the given sum
int minCoins(vector<int> &coins, int sum) {
    // code here
    int n = coins.size();
    vector<int> prev(sum+1, 1e9), cur(sum+1, 1e9);

    prev[0] = 0;

    for(int tar = 0; tar <= sum; tar++) {
        if(tar % coins[0] == 0) prev[tar] = tar/coins[0];
        else prev[tar] = 1e9;
    }

    for(int ind = 1; ind < n; ind++) {
        for(int tar = 0; tar <= sum; tar++) {
            int notTake = 0 + prev[tar];
            int take = 1e9;
            
            if(coins[ind] <= tar) take = 1 + cur[tar - coins[ind]];
            
            cur[tar] = min(notTake, take);
        }
        prev = cur;
    }

    int ans = prev[sum];

    if(ans >= 1e9) return -1;
    else return ans;
}



int main() {

    vector<int> coins =  {9, 6, 5, 1};
    int sum = 19; 
    cout << "The output is: " << minCoins(coins, sum);

    return 0;
}
