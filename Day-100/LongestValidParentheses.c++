// Longest Valid Parentheses Substring


// Problem-Link->    


#include<bits/stdc++.h>
using namespace std;


int maxLength(string &s) {
    int n = s.size();
    stack<int> st;

    // Push -1 as the initial index to 
    // handle the edge case
    st.push(-1);
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        // If we encounter an opening parenthesis,
        // push its index
        if(s[i] == '(') st.push(i);
        else {
            st.pop();

            // If stack is empty, push the current index 
            // as a base for the next valid substring
            if(st.empty()) st.push(i);
            else {
                // Update maxLength with the current length 
                // of the valid parentheses substring
                maxLen = max(maxLen, i - st.top());
            }
        }
    }

    return maxLen;
}


int main() {
    string s = ")()())"; 
    cout << "The output is: " << maxLength(s) << endl;

    return 0;
}
