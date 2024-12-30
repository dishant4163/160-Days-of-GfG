// Two Sum - Pair with Given Sum


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/key-pair5616    


#include<bits/stdc++.h>
using namespace std;

bool twoSum(vector<int>& arr, int target) {
    unordered_set<int> seen;

    for(int it : arr) {
        int complement = target - it;

        if(seen.find(complement) != seen.end()) return true;

        seen.insert(it);
    }

    return false;
}


int main() {

    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    if (twoSum(arr, target)) cout << "True";
    else cout << "False";

    return 0;


    return 0;
}
