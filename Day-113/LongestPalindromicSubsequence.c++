// Longest Palindromic Subsequence


// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-palindromic-subsequence-1612327878   



#include<bits/stdc++.h>
using namespace std;


int lcs(string &s, string &t) {
    int n = s.size(), m = t.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                cur[j] = 1 + prev[j-1];
            }
            else {
                cur[j] = max(prev[j], cur[j-1]);
            }
        }
        prev = cur;
    }

    return prev[m];
}


// Function to find the length of the lps
int longestPalinSubseq(string &s) {
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}



int main() {

    string s = "bbabcbcab";

    cout << "The output is: " << longestPalinSubseq(s);


    return 0;
}
