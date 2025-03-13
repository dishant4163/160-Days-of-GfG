// Palindrome Substrings Count



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/count-palindrome-sub-strings-of-a-string0652   



#include<bits/stdc++.h>
using namespace std;


int countPS(string &s) {
    int n = s.length(), cnt = 0;

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // diagonal is always palindrome i.e, 1-length substring/string 
    // is always palindrome
    for(int i=0; i<n; i++) dp[i][i] = true;

    // 2 length string/substring is palindrome if
    // both characters are same
    for(int i = 0; i < n-1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = true;
            cnt++;
        }
    }

    //Now, handle palindrome of length more than 2(gap >= 2)
    for(int gap = 2; gap < n; gap++) {
        for(int i=0; i < n-gap; i++) {
            int j = i+gap;

            //check if the current string is a palindrome
            if(s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                cnt++;
            }
        }
    }

    return cnt;
}



int main() {

    string s = "abaab";
    cout << "The output is: " << countPS(s);


    return 0;
}
