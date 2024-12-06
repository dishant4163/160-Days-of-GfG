// Search Pattern (KMP-Algorithm)

// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/search-pattern0205   


#include<bits/stdc++.h>
using namespace std;

//function to get LPS 
void getLPSArr(string& pat, vector<int>& lps) {
    lps[0] = 0;

    int len = 0, i = 1;

    while (i < pat.size()) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}


vector<int> search(string& pat, string& txt) {
    vector<int> lps(pat.length());
    vector<int> ans;

    getLPSArr(pat, lps);

    for(int i = 0, j = 0; i < txt.size();) {
        if(txt[i] == pat[j]) {
            i++; j++;
            if(j == pat.length()) {
                ans.push_back(i - j);
                j = lps[j-1];
            }
        }

        else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return ans;
}

int main() {

    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = search(pat, txt);
    cout << "The indices of occurrences of pat within txt is: ";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";


    return 0;
}
