// Longest Bounded-Difference Subarray / Longest Subarray With Absolute Difference B/w Any Pair At Most X



// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/queue-and-deque-gfg-160/problem/longest-bounded-difference-subarray  



#include<bits/stdc++.h>
using namespace std;


vector<int> longestSubarray(vector<int>& arr, int x) {
    int n = arr.size(), s = 0, e = 0;
    vector<int> ans;
    deque<int> minDq, maxDq;
    int resStart = 0, resEnd = 0;


    int n = arr.size(), s = 0, e = 0;
        deque<int> mindq, maxdq;
        vector<int> ans;
        int ansStart = 0, ansEnd = 0;
        
        while(e < n) {
            // pop element greater than curr element from mindq
            while(!mindq.empty() && arr[mindq.back()] > arr[e]) mindq.pop_back();

            // pop element smaller than curr element from maxdq
            while(!maxdq.empty() && arr[maxdq.back()] < arr[e]) maxdq.pop_back();
            // push current index to both dq
            mindq.push_back(e);
            maxdq.push_back(e);

            // check if the subarray has maximum difference less than X
            while(arr[maxdq.front()] - arr[mindq.front()] > x) {
                //reduce the length of sliding window by moving the start pointer
                if(s == mindq.front()) mindq.pop_front();
                if(s == maxdq.front()) maxdq.pop_front();
                s++; // slide the window
            }
            if(e-s > ansEnd - ansStart) {
                ansEnd = e;
                ansStart = s;
            }
            e++; // Expand the Window
        }

        // Construct and return the result subarray
        for(int i = ansStart; i <= ansEnd; i++) {
            ans.push_back(arr[i]);
        }

    return ans;
}


int main() {

    vector<int> arr = { 8, 4, 2, 6, 7 };
    int x = 4;

    vector<int> res = longestSubarray(arr, x);
    cout << "The output is: ";
    for (auto val: res) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
