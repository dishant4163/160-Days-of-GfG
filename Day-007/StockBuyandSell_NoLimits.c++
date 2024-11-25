// Stock Buy and Sell - Multiple Transaction Allowed


// Problem Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/stock-buy-and-sell2615 


#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
    // code here
    int maxProfit = 0;

    for(int i = 1; i < prices.size(); i++) {
            // solving greedily
            if(prices[i] > prices[i-1]) { 
            maxProfit += prices[i] - prices[i-1];
        }
    }

    return maxProfit;
}


int main() {

    vector<int> prices = { 100, 180, 260, 310, 40, 535, 695 };
    cout << "Maximum profit is: " << maximumProfit(prices) << endl;


    return 0;
}

