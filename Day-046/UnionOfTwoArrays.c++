// Union of Two Arrays with Duplicates


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/union-of-two-arrays3538


#include<bits/stdc++.h>
using namespace std;

int findUnion(vector<int>& a, vector<int>& b) {
    unordered_set<int> st;

    for(int i=0; i < a.size(); i++) {
        st.insert(a[i]);
    }

    for(int i=0; i < b.size(); i++) {
        st.insert(b[i]);
    }

    return st.size();
}



int main() {

    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    int res = findUnion(a, b);
    cout << "Union size is: " << res << endl;


    return 0;
}
