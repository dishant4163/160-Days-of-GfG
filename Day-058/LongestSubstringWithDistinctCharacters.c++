// Longest Substring With Distinct Characters


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/longest-distinct-characters-in-string5848


#include<bits/stdc++.h>
using namespace std;

int longestUniqueSubstr(string &s) {
    int n = s.size(), lptr = 0, rptr = 0, len = 0;

    //Base Case
    if((n==0) || (n == 1)) return s.size();

    vector<int> hashArr(256, -1); 

    while(rptr < n) {
        if(hashArr[s[rptr]] != -1 && hashArr[s[rptr]] >= lptr) {
            lptr = hashArr[s[rptr]] + 1;
        }

        len = max(len , (rptr - lptr + 1));
        hashArr[s[rptr]] = rptr;
        rptr++;
    }

    return len;
}


int main() {

    string s = "geeksforgeeks";
    cout << "The longest substring wit distinct characters is: " << longestUniqueSubstr(s);



    return 0;
}

