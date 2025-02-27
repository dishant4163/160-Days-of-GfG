// Next Greater Element (NGE)


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/next-larger-element-1587115620   



#include<bits/stdc++.h>
using namespace std;


vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for(int i = n-1; i >= 0; i--) {
        // Pop elements from the stack that are less
        // than or equal to the current element
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If the stack is not empty, the top element
        // is the next greater element
        if(!st.empty()) nge[i] = st.top();

        // push curr ele onto the stack
        st.push(arr[i]);
    }

    return nge;
}




int main() {

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextGreaterElement(arr);

    cout << "The output is : ";
    for(int it : res) {
        cout << it << " ";
    }
    cout << endl;


    return 0;
}
