// Check if two Strings are Anagrams of each other / Anagram Check

// Problem-Link ->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/anagram-1587115620   



#include<bits/stdc++.h>
using namespace std;

bool areAnagrams(string &s, string &t) {
    //Edge Case
    if (s.size() != t.size()) return false;

    //Declare vector count array of size 26
    //initialize with zero
    vector<int> cntFreq(26, 0);  

    for(int i = 0; i < s.size(); i++) {
        cntFreq[s[i] - 'a']++;
        cntFreq[t[i] - 'a']--;
    }

    for(int i = 0; i < cntFreq.size(); i++) {
        if(cntFreq[i] != 0) return false;
    }

    return true;
}


int main() {

    string s = "geeks";
    string t = "kseeg";
    cout << (areAnagrams(s, t) ? "true" : "false") << endl;

    return 0;
}
