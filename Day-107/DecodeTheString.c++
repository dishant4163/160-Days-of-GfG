// Decode The String / Decode a string recursively encoded as count followed by substring


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/decode-the-string2444    



#include<bits/stdc++.h>
using namespace std;


// Function to decode the pattern string 's'
string decodedString(string &str) {
    int n = str.length();
    stack<char> st;

    for(int i = 0; i < n; i++) {
        //push character into stack until ']' is encounter
        if(str[i] != ']') {
            st.push(str[i]);
        }
        else { // decode when ']' is found
            string temp;

            // pop char until '[' is found
            while (!st.empty() && st.top() != '[') {
                temp.push_back(st.top());
                st.pop();
            }
            // reverse extracted string
            reverse(temp.begin(), temp.end());
            st.pop(); // remove '[' from the stack

            string num;
            //extract the number (repetition cnt) from the stack
            while(!st.empty() && isdigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }

            // convert extracted number to integer
            int Num = stoi(num);
            string repeat;

            // repeat the extracted string 'number' times
            for(int j = 0;  j < Num; j++) {
                repeat.append(temp);
            }

            // push the expandex string back onto the stack
            for(char ch : repeat) {
                st.push(ch);
            }
        }
    }

    string ans = "";
    // pop all characters from the stack to the ans
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    // reverse to get correct order
    reverse(ans.begin(), ans.end());

    return ans;
}



int main() {
    string s = "3[b2[ca]]";
    cout << "The output is: " << decodedString(s) << endl;
    return 0;
}
