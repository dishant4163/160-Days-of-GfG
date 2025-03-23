// Stock Buy and Sell - At-most k Transactions Allowed


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/maximum-profit4657   



#include <bits/stdc++.h>
using namespace std;

// Function to return max profit from k transactions
int maxProfit(vector<int> &prices, int k) {
    // code here
    int n = prices.size();

    if(n==0 || k==0) return 0;

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= k; cap++) {
                
                if(buy == 1) { // buy stock
                    dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                }
                else { // sell stock
                    dp[i][buy][cap] = max(prices[i]+dp[i+1][1][cap-1], dp[i+1][0][cap]);
                }
                
            }
        }
    }

    return dp[0][1][k];
}



int main() {

    int k = 2;
    vector<int> prices = {10, 22, 5, 80};
    cout << "The output is: " << maxProfit(prices, k) << endl;

    return 0;
}
