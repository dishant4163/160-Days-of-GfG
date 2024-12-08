// Strings Rotations of Each Other


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/check-if-strings-are-rotations-of-each-other-or-not-1587115620   


#include<bits/stdc++.h>
using namespace std;

vector<int> getLPSArr(string& pat) {
    vector<int> lps(pat.size());

    lps[0] = 0;
    int len = 0, i = 1;

    while(i < pat.size()) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else if(pat[i] != pat[len]) {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool areRotations(string& s1, string& s2) {
    string txt = s1 + s1, pat = s2;
    int n = txt.size(), m = pat.size();

    vector<int> lps = getLPSArr(pat);

    int i = 0, j = 0;

    while(i < n) {
        if(txt[i] == pat[j]) {
            i++; j++;
        }

        if(j == m) return true;

        else if(i < n && pat[j] != txt[i]) {
            if(j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return false;
}


int main() {

    string s1 = "aab";
    string s2 = "aba";

    cout << (areRotations(s1, s2) ? "true" : "false");

    return 0;
}
