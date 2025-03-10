// Longest Common Subsequence(LCS)


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-common-subsequence-1587115620  


#include<bits/stdc++.h>
using namespace std;


int lcs(string &s1, string &s2) {
    // code here
    int n = s1.size(), m = s2.size();
    
    vector<int> prev(m+1, 0), cur(m+1, 0);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(cur[j-1], prev[j]);
        }
        prev = cur;
    }
    
    return prev[m];
}



int main() {

    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << "The output is: " << lcs(s1, s2) << endl;



    return 0;
}
