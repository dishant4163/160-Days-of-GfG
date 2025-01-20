// Longest Subarray With Equal Number of 0s & 1s


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/largest-subarray-of-0s-and-1s   



#include<bits/stdc++.h>
using namespace std;


int maxLen(vector<int> &arr) {
    unordered_map<int, int> mp;
    int preSum = 0, maxLen = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        // add current element to sum if current 
        // element is zero then add -1 else 1
        preSum += (arr[i] == 0) ? -1 : 1;

        if(preSum == 0) maxLen = i + 1; // handle sum = 0 at last index

        // if this sum is seen before than update answer with maximum
        if(mp.find(preSum) != mp.end()) {
            maxLen = max(maxLen, i - mp[preSum]);
        }

        else { // else put in sum in map
            mp[preSum] = i;
        }
    }

    return maxLen;
}




int main() {

    vector<int> arr = {1, 0, 0, 1, 0, 1, 1};
    cout << "The longest subarray with equal numbers of 0's & 1's is: " << maxLen(arr) << endl;


    return 0;
}
