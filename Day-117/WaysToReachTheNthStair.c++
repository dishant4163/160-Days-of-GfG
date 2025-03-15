// Ways to Reach the Nth Stair


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/count-ways-to-reach-the-nth-stair-1587115620  


#include<bits/stdc++.h>
using namespace std;


int countWays(int n) {
    // your code here
    int prev1 = 1, prev2 = 1;

    for(int i = 2; i <= n; i++) {
        int cur_i = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur_i;
    }
    return prev1;
}


int main() {

    int n = 4;
    cout << "The output is: " << countWays(n);


    return 0;
}
