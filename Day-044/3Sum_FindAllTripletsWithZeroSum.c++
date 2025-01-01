// 3 Sum - Find All Triplets with Zero Sum


// Problem-Link->
// 


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>& arr) {
    // ordered set to handle duplicates
    set<vector<int>> ansSet;
    int n = arr.size();
    unordered_map<int, vector<pair<int, int>>> mp;

    // store sum of all pairs
    for(int i=0; i < n; i++) {
        for(int j = i+1; j < n; j++) 
            mp[arr[i] + arr[j]].push_back({i, j});
    }

    for (int i=0; i < n; i++) {
        int leftEle = -arr[i];
        if (mp.find(leftEle) != mp.end()) {
            vector<pair<int, int>> pairs = mp[leftEle];

            for(auto it : pairs) {
                // no 2 same indices in same triplets
                if(it.first != i && it.second != i) {
                    vector<int> curr = {i, it.first, it.second};
                    sort(curr.begin(), curr.end());
                    ansSet.insert(curr);
                }
            }
        }
    }

    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}



int main() {

    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> res = findTriplets(arr);
    for (int i = 0; i < res.size(); i++)
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;


    return 0;
}
