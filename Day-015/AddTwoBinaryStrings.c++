// Add Two Binary Strings  

// Problem-Link
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/add-binary-strings3805   


#include<bits/stdc++.h>
using namespace std;

//Function to trim leading zeros
string removeLeadingZeros(string& str) {
    int i = 0;
    while(str[i] == '0') {
        i++;
    }

    return str.substr(i);
}

string addBinary(string& s1, string& s2) {
    s1 = removeLeadingZeros(s1);
    s2 = removeLeadingZeros(s2);

    if(s1.size() < s2.size()) {
        return addBinary(s2, s1);
    }

    int i = s1.size() - 1;
    int j = s2.size() - 1;

    int carry = 0;
    string ans = "";

    while(i >= 0 || carry) {
        int sum = carry;
        if(i >= 0) {
            sum += s1[i] - '0';
            i--;
        }
        if(j >= 0) {
            sum += s2[j] - '0';
            j--;
        }

        ans = char((sum % 2) + '0') + ans;
        carry = sum / 2;
    }

    return ans;
}


int main() {

    string s1 = "1101", s2 = "111";
    cout << addBinary(s1, s2) << endl;

    return 0;
}
