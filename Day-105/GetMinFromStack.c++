// Get Min from Stack / Design a stack that supports getMin() in O(1) time


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/get-minimum-element-from-stack   



#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    stack<int> st;
    int minEle;

public:
    Solution() {
        // code here
    }
// Add an element to the top of Stack
void push(int x) {
    // code here
    if(st.empty()) minEle = x;
    else if(x <= minEle) {
        st.push(minEle);
        minEle = x;
    } 
    st.push(x);
}

// Remove the top element from the Stack
void pop() {
    // code here
    if(st.empty()) return;
    int topp = st.top();
    st.pop();
    
    if(topp == minEle && !st.empty()) {
        minEle = st.top();
        st.pop();
    }
}

// Returns top element of the Stack
int peek() {
    // code here
    if(st.empty()) return -1;
    return st.top();
}

// Finds minimum element of Stack
int getMin() {
    // code here
    if(st.empty()) return -1;
    return minEle;
}
};


int main() {

    Solution sol;

    cout << "The output is: ";
    // Function calls
    sol.push(2);
    sol.push(3);
    cout << sol.peek() << " ";
    sol.pop();
    cout << sol.getMin() << " ";
    sol.push(1);
    cout << sol.getMin() << " ";

    return 0;
}

