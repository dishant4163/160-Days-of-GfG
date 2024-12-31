// 2 Sum - Count Pairs with Given Sum


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-pairs-with-given-sum--150253


#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& arr, int x) {
    unordered_map<int, int> freq;
    int cnt = 0;

    for(int i=0; i < arr.size(); i++) {
        if(freq.find(x - arr[i]) != freq.end()) {
            cnt += freq[x - arr[i]];
        }

        freq[arr[i]]++;
    }

    return cnt;
}




int main() {

    vector<int> arr = {1, 5, 7, -1, 5}; 
    int target = 6; 
    cout << "Number of Count Pairs with Given Sum is " << countPairs(arr, target);    

    return 0;
}
