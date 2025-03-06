//  Sliding Window Maximum (Maximum of all subarrays of size K) / K Sized Subarray Maximum


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/queue-and-deque-gfg-160/problem/maximum-of-all-subarrays-of-size-k3101



#include <bits/stdc++.h>
using namespace std;


vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    int n = arr.size();

    vector<int> ans;

    deque<int> dq(k); //decalre dq to store max k values

    // Process first k (or first window) elements of array
    for(int i =0; i <k; i++) {
        // For every element, the previous smaller elements 
        // are useless so remove them from dq
        while(!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back(); // remove from the rear/end
        }
        // add new element at rear of dq
        dq.push_back(i);
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for(int i = k; i < n; i++) {
        // The element at the front of the queue is the largest 
        // element of previous window, so store it
        ans.push_back(arr[dq.front()]);

        //remove the elements which are out of thsi window
        while(!dq.empty() && dq.front() <= i - k) {
            // remove from the front of dq
            dq.pop_front();
        }

        // Remove all elements smaller than the currently being 
        // added element (remove useless elements)
        while(!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        // add current element at rear of dq
        dq.push_back(i);
    }

    ans.push_back(arr[dq.front()]);

    return ans;
}




int main() {
    vector<int> arr = {1, 3, 2, 1, 7, 3};
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    cout << "The output is: ";
    for (int maxVal : res) {
        cout << maxVal << " ";
    }
    return 0;
}
