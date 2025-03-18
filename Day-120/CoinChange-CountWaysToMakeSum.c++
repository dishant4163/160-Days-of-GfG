// Coin Change - Count Ways To Make Sum


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/coin-change2448   


#include<bits/stdc++.h>
using namespace std;

int count(vector<int>& coins, int sum) {
    // code here.
    int n = coins.size();

    vector<int> prev(sum+1, 0), cur(sum+1, 0);

    for(int i = 0; i <= sum; i++) {
        prev[i] = (i%coins[0] == 0);
    }

    for(int ind = 1; ind < n; ind++) {
        for(int target = 0; target <= sum; target++) {
            int notTake = prev[target];
            int take = 0;

            if(coins[ind] <= target) take = cur[target - coins[ind]];

            cur[target] = notTake + take; 
        }
        prev = cur;
    }

    return prev[sum];
}


int main() {

    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << "The output is: " << count(coins, sum);

    return 0;
}
