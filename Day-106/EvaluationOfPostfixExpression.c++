// Evaluation of Postfix Expression



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/evaluation-of-postfix-expression1735  




#include<bits/stdc++.h>
using namespace std;


// Function to evaluate a postfix expression given as a vector of strings
int evaluatePostfix(vector<string>& arr) {
    stack<int> st;

    for(string it : arr) {
        // if it is a number push it onto stack
        if(isdigit(it[0]) || (it.size() > 1 && it[0] == '-')) {
            st.push(stoi(it));
        }
        else {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();

            if(it == "+") {
                st.push(val2 + val1);
            } 
            else if(it == "-") {
                st.push(val2 - val1);
            }
            else if(it == "*") {
                st.push(val2 * val1);
            } 
            else if(it == "/") {
                st.push(val2 / val1);
            }
        }
    }

    return st.top();
}


int main() {

    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};
    cout << "The output is: " << evaluatePostfix(arr) << endl; 


    return 0;
}
