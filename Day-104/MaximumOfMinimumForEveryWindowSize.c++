// Maximum of minimums of every window size in a given array


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/maximum-of-minimum-for-every-window-size3453    



#include<bits/stdc++.h>
using namespace std;


vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;

    // array to store length of window, where each element is minimum
    vector<int> len(n, 0);

    //iterate through array to find window size using stack
    for(int i = 0; i < n; i++) {
        // process elements to find next smaller element on the left
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            int curTop = st.top();
            st.pop();

            int windowSize = st.empty() ? i : i - st.top()-1;
            len[curTop] = windowSize;
        }
        st.push(i);
    }

    // process remaining elements in the stack for right boundaries
    while(!st.empty()) {
        int curTop = st.top();
        st.pop();
        int windowSize = st.empty() ? n : n - st.top()-1;
        len[curTop] = windowSize;
    }

    // fill ans based on len & arr
    for(int i = 0; i < n; i++) {
        int windowSize = len[i] - 1; // 0-based indexing
        ans[windowSize] = max(arr[i], ans[windowSize]);
    }

    // fill the remaining entris in ans to ensure all are max in min
    for(int i = n-2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i+1]);
    }

    return ans;
}



int main() {
    vector<int> arr = { 10, 20, 30, 50, 10, 70, 30 };
    vector<int> res = maxOfMins(arr);
    cout << "The output is: ";
    for (int x : res)
        cout << x << " ";
    return 0;
}
