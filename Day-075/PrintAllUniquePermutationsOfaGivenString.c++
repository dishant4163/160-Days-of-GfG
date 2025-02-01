// Print All Unique Permutations of a String


// PRoblem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/permutations-of-a-given-string2041


#include<bits/stdc++.h>
using namespace std;

void getPermutationStr(string& s, vector<string>& ans, string& curStr, vector<bool>& isSeenStr) {
    // Base case
    if(curStr.size() == s.size()) {
        ans.push_back(curStr);
        return;
    }

    for(int i = 0; i < s.size(); i++) {
        if(isSeenStr[i]) continue; // skip already used character

        // skip duplicates, if current char is same as seen previously
        if(i > 0 && s[i] == s[i - 1] && !isSeenStr[i-1]) continue;

        isSeenStr[i] = true;
        curStr.push_back(s[i]);

        getPermutationStr(s, ans, curStr, isSeenStr);

        //Backtrack
        curStr.pop_back(); // remove the character
        isSeenStr[i] = false; // not seen previously
    }
}


vector<string> findPermutation(string &s) {
    int n = s.size();
    vector<string> ans;
    string cur = "";
    sort(s.begin(), s.end());
    vector<bool> isSeenStr(n, false);
    getPermutationStr(s, ans, cur, isSeenStr);

    return ans;
}



int main() {

    string s = "ABC";
    vector<string> res = findPermutation(s);

    for (string perm: res)
        cout << perm << " ";


    return 0;
}
