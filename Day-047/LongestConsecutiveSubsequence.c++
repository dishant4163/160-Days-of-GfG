//  Longest Consecutive Subsequence


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/longest-consecutive-subsequence2449




#include<bits/stdc++.h>
using namespace std;

int  longestConsecutive(vector<int>& arr) {
    int n = arr.size(), longest = 1;
    if(n == 0) return 0;

    unordered_set<int> st;
    for(int i=0; i < n; i++) {
        st.insert(arr[i]);
    }

    for(auto it : st) {
        //if 'it' is a starting num
        if(st.find(it - 1) == st.end()) {
            int cnt = 1, curr = it;
            while(st.find(curr + 1) != st.end()) {
                curr++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}


int main() {

    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};
    cout << "Longest Consecutive Subsequence is: " << longestConsecutive(arr);
    return 0;


    return 0;
}
