// Stock Buy and Sell – Max 2 Transactions Allowed


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/buy-and-sell-a-share-at-most-twice   


#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int> &prices) {
    // code here
    int n = prices.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= 2; cap++) {
                //buy stock
                if(buy == 1) {
                    //buy or skip
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]);
                }
                // sell stock
                else {
                    // sell or skip
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                }

            }
        }
    }

    return dp[0][1][2];
}


int main() {

    vector<int> price = { 10, 22, 5, 75, 65, 80 };
    cout << "The output is: " << maxProfit(price);


    return 0;
}
