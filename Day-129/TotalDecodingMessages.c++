// Total Decoding Messages / Count Possible Decoding of a given Digit Sequence


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/total-decoding-messages1235  


#include<bits/stdc++.h>
using namespace std;


int countWays(string &digits) {
    // code here
    int n = digits.size();

    vector<int> dp(n+1, 0);

    //Base case (empty string has 1 valid decoding)
    dp[n] = 1;

    for(int i = n-1; i >= 0; i--) {
        //single digit decoding (check if current digit is not '0')
        if(digits[i] != '0') dp[i] = dp[i+1];

        //two-digit decoding(check if next two digits are valid)
        if((i + 1 < n) && ((digits[i] == '1' && digits[i+1] <= '9')
                        || (digits[i] == '2' && digits[i+1] <= '6') ) ) {
                            dp[i] = dp[i] + dp[i+2];
                        }
    }

    return dp[0];
}



int main() {

    string digits  = "121";
    cout << "The output is: " << countWays(digits) << endl;



    return 0;
}
