// Edit Distance


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/edit-distance3702   



#include<bits/stdc++.h>
using namespace std;


int editDistance(string& s1, string& s2) {
    // code here
    int n = s1.size(), m = s2.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);

    for(int i = 0; i <= m; i++) prev[i] = i;

    for(int i = 1; i <= n; i++) {
        cur[0] = i; // update current
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) cur[j] = prev[j-1];
            else {
                cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
            }
        }
        prev = cur;
    }

    return prev[m];
}




int main() {

    string s1 = "abcd";
    string s2 = "bcfe";

    cout << "The output is: " << editDistance(s1, s2);


    return 0;
}
