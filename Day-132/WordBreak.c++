// Word Break



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/word-break1352  


#include<bits/stdc++.h>
using namespace std;



bool wordBreak(string &s, vector<string> &dictionary) {
    //code here
    int n = s.size();
    vector<bool> dp(n+1, false);

    // base case
    dp[0] = true;

    //traverse in given string
    for(int i = 1; i <= n; i++) {
        //now traverse through the given dictionary words
        for(string &word : dictionary) {
            // check if curr word is present, prefix before the word
            // is also breakable
            int start = i - word.size();

            if(start >= 0 && dp[start] && s.substr(start, word.size()) == word ){
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}




int main() {

    string s = "ilike";
    vector<string> dictionary = {"i", "like", "gfg"};

    cout << "Output:- " << (wordBreak(s, dictionary) ? "true" : "false") << endl;


    return 0;
}
