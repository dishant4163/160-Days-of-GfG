// Count SubArrays With Given XOR


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-subarray-with-given-xor



#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarrayXOR(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    int ans = 0, xorr = 0, n = arr.size();

    for(int i=0; i < n; i++) {
        xorr ^= arr[i];

        ans += mp[xorr ^ k];

        if(xorr == k) ans++;

        mp[xorr]++;
    }

    return ans;
}



int main() {

    vector<int> arr = { 4, 2, 2, 6, 4 };
    int k = 6;

    cout << "The number of subarrays with XOR k is: "  << subarrayXOR(arr, k); 


    return 0;
}
