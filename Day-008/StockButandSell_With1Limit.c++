// Stock Buy and Sell (with 1 Limit)


//Problem Link->
//      

#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int>& prices) {
    int minValue = prices[0], ans = 0;

    for(int i = 1; i < prices.size(); i++) {
        minValue = min(prices[i], minValue);

        ans = max(ans, prices[i] - minValue);
    }

    return ans;
}



int main() {

    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << "Maximum profit is: " << maximumProfit(prices) << endl;


    return 0;
}
