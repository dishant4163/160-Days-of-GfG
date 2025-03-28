// Matrix Chain Multiplication (MCM)



// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/matrix-chain-multiplication0303   


#include<bits/stdc++.h>
using namespace std;


int matrixMultiplication(vector<int> &arr) {
    // code here
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n-1; i >= 1; i--) {
        for(int j = i+1; j < n; j++) {
            int mini = 1e9;

            for(int k = i; k < j; k++) {
                int steps = arr[i-1] * arr[k] * arr[j] +
                            dp[i][k] + dp[k+1][j];

                mini = min(steps, mini);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}



int main() {

    vector<int> arr = {2, 1, 3, 4};
    cout << "The output is: " << matrixMultiplication(arr);


    return 0;
}
