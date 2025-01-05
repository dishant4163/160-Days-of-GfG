// Print Anagrams Together


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/print-anagrams-together

#include<bits/stdc++.h>
using namespace std;


string getHashVal(string& s) {
    string resHash = "";
    vector<int> freq(26, 0);

    for(char ch : s) {
        freq[ch - 'a'] += 1;
    }

    for(int i=0; i < 26; i++) {
        resHash.append(to_string(freq[i]));
        resHash.append("$");
    }

    return resHash;
}


vector<vector<string>> anagrams(vector<string>& str) {
    vector<vector<string>> ans;
    unordered_map<string, int> mp;

    for(int i=0; i < str.size(); i++) {
        string s = getHashVal(str[i]);

        if(mp.find(s) == mp.end()) {
            mp[s] = ans.size();
            ans.push_back({});
        }

        ans[mp[s]].push_back(str[i]);
    }

    return ans;
}


int main() {

    vector<string> arr = {"act", "god", "cat", "dog", "tac"};

    vector<vector<string>> res = anagrams(arr);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }




    return 0;
}
