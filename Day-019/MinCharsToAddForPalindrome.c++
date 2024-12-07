// Min Chars to Add for Palindrome

// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/minimum-characters-to-be-added-at-front-to-make-string-palindrome

#include <bits/stdc++.h>
using namespace std;

vector<int> getLPS(string &pat) {
    vector<int> lps(pat.size());

    lps[0] = 0;
    int len = 0, i = 1;

    while (i < pat.size()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else if (pat[i] != pat[len]) {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int minChar(string &s) {
    int n = s.size();
    string revStr = s;

    reverse(revStr.begin(), revStr.end());

    s = s + "$" + revStr;

    vector<int> lps = getLPS(s);

    return (n - lps.back());
}

int main() {
    string s = "AACECAAAA";
    cout << "Minimum number of Characters required to Add in front for Palindrome is: " << minChar(s);

    return 0;
}
