// Min Cost Climbing Stair/Minimum Cost to Reach the Top


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/min-cost-climbing-stairs  


#include<bits/stdc++.h>
using namespace std;


int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();

    if(n == 1) return cost[0];

    int prev2 = cost[0], prev1 = cost[1];

    for(int i = 2; i < n; i++) {
        int cur_i = cost[i] + min(prev1, prev2);

        prev2 = prev1;
        prev1 = cur_i;
    }

    // Return minimum of cost to climb (n-1)th stair and 
    // cost to reach (n-2)th stair
    return min(prev2, prev1);
}



int main() {

    vector<int> cost = { 16, 19, 10, 12, 18 };
    cout << "The output is: " << minCostClimbingStairs(cost) << endl;


    return 0;
}
