// Largest Rectangular Area in a Histogram / Histogram Max Rectangular Area


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/maximum-rectangular-area-in-a-histogram-1587115620 



#include <bits/stdc++.h>
using namespace std;



// Function to calculate the maximum rectangular area
int getMaxArea(vector<int> &arr) {
    // Your code here
    int n = arr.size();
    stack<int> st;
    int maxAr = 0;
    
    for(int i = 0; i <= n; i++) {
        while(!st.empty() &&(i==n || arr[st.top()] >= arr[i])) {
            int ht = st.top();
            st.pop();
            
            int width = st.empty() ? i : i-st.top()-1;
            
            maxAr = max(maxAr, arr[ht] *width);
        }
        st.push(i);
    }


// to avoid this while loop extra condition check for remainig element
// we do in upper while loop to add a ((i==n) or ) with this -> (arr[st.top()] >= arr[i])

    // // For the remaining items in the stack, next smaller does not
    // // exist. Previous smaller is the item just below in stack
    // while(!st.empty()) {
    //     int h = st.top(); st.pop();
    //     int w = st.empty() ? n : n - st.top()-1;
    //     maxAr = max(maxAr, arr[h] * w);
    // }

    return maxAr;
}



int main() {
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << "The output is: " << getMaxArea(arr);
    return 0;
}
