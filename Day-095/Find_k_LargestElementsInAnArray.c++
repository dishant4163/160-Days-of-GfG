// Find k largest elements in an array | Heap



// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/k-largest-elements4206   



#include<bits/stdc++.h>
using namespace std;


vector<int> kLargest(vector<int>& arr, int k) {
    int n = arr.size();

    //decalring Priority Queue(Min-Heap) with 1st K element of arr
    priority_queue<int, vector<int>, greater<int>> minH(arr.begin(), arr.begin() + k);

    // Traverse (n-k) elements
    for(int i = k; i < n; i++) {
        // if top of heap is less than arr[i] then,
        // remove top elements & add arr[i]
        if(minH.top() < arr[i]) {
            minH.pop();
            minH.push(arr[i]);
        }
    }

    vector<int> ans;

    // heap will contains anly k laregest elements
    while(!minH.empty()) {
        ans.push_back(minH.top());
        minH.pop();
    }

    // Reverse the result array, so that all
    // elements are in decreasing order
    reverse(ans.begin(), ans.end());
    return ans;
}



int main() {
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;

    vector<int> res = kLargest(arr, k);
    cout << "The output is: " ;
    for(int ele : res)
        cout << ele << " ";

    return 0;
}
