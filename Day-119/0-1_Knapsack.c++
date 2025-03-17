// 0/1 Knapsack


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/0-1-knapsack-problem0945    


#include<bits/stdc++.h>
using namespace std;


// Function to find the maximum profit
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size();

    vector<int> prev(W+1, 0);

    for(int ind = 1; ind <= n; ind++) {
        for(int ind = 1; ind <= n; ind++) {
            for(int j = W; j >= wt[ind - 1]; j--) {
                prev[j] = max(prev[j], val[ind - 1] + prev[j - wt[ind - 1]]);
            }
        }
    }

    return prev[W];
}



int main() {

    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << "The output is: " << knapsack(W, val, wt) << endl;

    return 0;
}
