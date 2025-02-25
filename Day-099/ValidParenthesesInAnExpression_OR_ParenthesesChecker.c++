// Valid Parentheses in an Expression / Parentheses Checker



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/parenthesis-checker2744  



#include<bits/stdc++.h>
using namespace std;

// solving using Stack
bool isBalanced(string& s) {
    stack<char> st;

    for(char ch : s) {
        if(ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        else {
            if(!st.empty() && 
            (st.top() == '(' && ch == ')') ||
            (st.top() == '{' && ch == '}') ||
            (st.top() == '[' && ch == ']')) {
                st.pop();
            }
            else {
                // unmatched closing bracket
                return false;
            }
        }
    }

    // if stack is empty, return true(balanced), else false
    return st.empty();
}





int main() {

    string s = "{([])}";

    if (isBalanced(s))
        cout << "true";
    else
        cout << "false";


    return 0;
}

