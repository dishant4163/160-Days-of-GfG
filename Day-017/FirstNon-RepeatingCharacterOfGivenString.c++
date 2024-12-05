// Find First Non-Repeating Character of Given String  

// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/non-repeating-character-1587115620       


#include<bits/stdc++.h>
using namespace std;

char nonRepeatingChar(string& s) {
    vector<int> freqArr(26, 0);

    for(int i = 0; i < s.size(); i++) {
        freqArr[s[i] - 'a']++;
    }

    for(int i=0; s.size(); i++) {
        if(freqArr[s[i] - 'a'] == 1) return s[i];
    }

    return '$';
}


int main() {

    string s = "racecar";
    cout << "First non-repeating character of given string is: " << nonRepeatingChar(s) << endl;


    return 0;
}
