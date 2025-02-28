// Stock Span Problem



// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/stock-span-problem-1587115621



#include<bits/stdc++.h>
using namespace std;


// Function to calculate stock span values
vector<int> calculateSpan(vector<int>& arr) {
    int n = arr.size();
    vector<int> span(n);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        // Remove elements from the stack while the current
        // price is greater than or equal to stack's top price
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        // If stack is empty, all elements to the left are smaller
        // Else, top of the stack is the last greater element's index
        if(st.empty()) span[i] = i+1;
        else span[i] = (i - st.top());

        //push the current index to the stack
        st.push(i);
    }

    return span;
}


int main() {

    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> span = calculateSpan(arr);

    cout << "The output is : ";
    for (int x : span) {
        cout << x << " ";
    }


    return 0;
}
