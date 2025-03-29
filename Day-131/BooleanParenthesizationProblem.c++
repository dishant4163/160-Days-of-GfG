// Boolean Parenthesization Problem(count ways) / (Similar too Evaluate Boolean Expression to True)



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/boolean-parenthesization5610    



#include<bits/stdc++.h>
using namespace std;


int countWays(string & str) {
    //code here
    int n = str.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));

    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j <= n-1; j++) {
            // Base case 1: i > j is an invalid case, so continue
            if(i > j) continue;

            for(int isTrue = 0; isTrue <= 1; isTrue++) {
                // Base case 2: i == j, evaluate the single character
                if(i == j) {
                    if(isTrue) dp[i][j][isTrue] = str[i] == 'T';
                    else dp[i][j][isTrue] = str[j] == 'F';
                    continue;
                }

                //Recurrence Logic:
                int cntWays = 0;

                for(int idx = i+1; idx <= j-1; idx += 2) {
                    int lT = dp[i][idx-1][1];
                    int lF = dp[i][idx-1][0];
                    int rT = dp[idx+1][j][1];
                    int rF = dp[idx+1][j][0];
    
                    if(str[idx] == '&') {
                        if(isTrue) cntWays += (lT * rT);
                        else cntWays += (lT * rF) + (lF * rT) + (lF * rF);
                    }
                    else if(str[idx] == '|') {
                        if(isTrue) cntWays += (lT * rT) + (lF * rT) + (lT * rF);
                        else cntWays += (lF * rF);
                    }
                    else {
                        if(isTrue) cntWays += (lF * rT) + (lT * rF);
                        else cntWays += (lF * rF) + (lT * rT);
                    }
                }

                dp[i][j][isTrue] = cntWays;
            }

        }
    }

    return dp[0][n-1][1];
}



int main() {

    string s = "T|T&F^T";
    cout << "The output is: " << countWays(s) << endl;


    return 0;
}
