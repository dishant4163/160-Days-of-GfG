// Minimize the Heights-2 / Minimize the maximum difference between the heights   

//Problem-Link
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/minimize-the-heights3351   


/* // NOTE:-
  Given an array arr[] denoting heights of N towers and a positive integer K.
  For each tower, you must perform exactly one of the following operations exactly once.

 # Increase the height of the tower by K
 # Decrease the height of the tower by K

  Find out the minimum possible difference between the height of the shortest 
and tallest towers after you have modified each tower.

  Note: It is compulsory to increase or decrease the height by K for each tower.
After the operation, the resultant array should not contain any negative integers.

TC:- O(N logN) + O(N)
SC:- O(N), for storing answer
*/

#include<bits/stdc++.h>
using namespace std;

// Function to minimize the maximum difference
int getMinDiff(vector<int>& arr, int k) {

    int n = arr.size();
    //sort the array
    sort(arr.begin(), arr.end());

    // If we increase all heights by k or decrease all
    // heights by k, the result will be arr[n - 1] - arr[0]
    int ans = arr[n - 1] - arr[0];

    for(int i = 1; i < n; i++) {

        if(arr[i] - k < 0) continue;

        int minHeight = min(arr[0] + k, arr[i] - k);
        int maxHeight = max(arr[i - 1] + k, arr[n-1] - k);

        ans = min(ans, maxHeight - minHeight);
    }

    return ans;
}

int main() {

    int k = 6;
    vector<int> arr = {12, 6, 4, 15, 17, 10};

    int ans = getMinDiff(arr, k);
    cout << ans;


    return 0;
}
