// Longest String Chain - Chain of Words in an Array



// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-string-chain  



#include<bits/stdc++.h>
using namespace std;


// Function to find the length of the longest string chain
bool checkPossible(string& s, string& t) {
    if(s.size() != t.size()+1) return false;
    
    int first = 0, second = 0;
    
    while(first < s.size()) {
        if(second < t.size() && s[first] == t[second]) {
            first++;
            second++;
        }
        else first++;
    }
    
    if(first == s.size() && second == t.size()) return true;
    else return false;
}

static bool comp(string& s, string &t) {
    return s.size() < t.size(); 
}

int longestStringChain(vector<string>& words) {
    // Code here
    int n = words.size();
    int maxLen = 1;
    vector<int> dp(n, 1);
    
    // sort in increasing order acc. to length
    sort(words.begin(), words.end(), comp); 
    
    for(int ind = 0; ind < n; ind++) {
        for(int prev = 0; prev < ind; prev++) {
            if(checkPossible(words[ind], words[prev]) && 1+dp[prev] > dp[ind]) {
                dp[ind] = 1 + dp[prev];
            }
        }
        if(dp[ind] > maxLen) {
            maxLen = dp[ind];
        }
    }
    
    return maxLen;
}


int main() {

    vector<string> words = { "a", "b", "ba", "bca", "bda", "bdca" };
    cout << "The output is: " << longestStringChain(words) << endl;


    return 0;
}
