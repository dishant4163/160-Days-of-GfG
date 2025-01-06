// Count Subarrays With Sum K


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/subarrays-with-sum-k  



#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& arr, int k) {
    unordered_map<int, int> mp;

    int n = arr.size(), ans = 0, sum = 0;

    for(int i=0; i < n; i++) {
        sum += arr[i];

        if(sum == k) ans++;
        if(mp.find(sum - k) != mp.end()) {
            ans += mp[sum - k];
        }

        mp[sum]++;
    }

    return ans;
}



int main() {

    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << "No. of subarrays whose sum " << k <<" is: " << countSubarrays(arr, k);

    return 0;
}
