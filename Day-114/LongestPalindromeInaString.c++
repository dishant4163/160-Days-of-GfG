// Longest Palindrome in a String



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-palindrome-in-a-string3411  



#include<bits/stdc++.h>
using namespace std;


string longestPalindrome(string& str) {
    int n = str.size();

    if(n == 0) return "";

    int s = 0, maxLen = 1;

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    //all substring having length 1 are palindromes
    for(int i = 0; i < n; i++) {
        dp[i][i] = true; // diagonal elements are 1 length palindromes, i.e., true
    }

    //Now, check for 2 length substring
    for(int i = 0; i < n-1; i++) {
        if(str[i] == str[i+1]) {
            dp[i][i+1] = true;
            if(maxLen < 2) {
                s = i; 
                maxLen = 2;
            }
        }
    }

    // check for lengths more than 2
    for(int len = 3; len <= n; len++) { 
        for(int i = 0; i < n-len+1; i++) {
            int j = i+len-1;

            if(dp[i+1][j-1] && str[i] == str[j]) {
                dp[i][j] = true;
                if(len > maxLen) {
                    s = i;
                    maxLen = len;
                }
            } 
        }
    }

    return str.substr(s, maxLen);
}


int main() {

    string s = "forgeeksskeegfor";
    cout << "The output is: " << longestPalindrome(s) << endl;


    return 0;
}
