// Intersection Of Two Arrays with Duplicates Elements


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/intersection-of-two-arrays-with-duplicate-elements   


#include<bits/stdc++.h>
using namespace std;


vector<int> intersection(vector<int>& a, vector<int>& b) {
    unordered_set<int> setA(a.begin(), a.end());
    vector<int> ans;

    for(int i=0; i < b.size(); i++) {
        if(setA.find(b[i]) != setA.end()) {
            ans.push_back(b[i]);
            setA.erase(b[i]);
        }
    }

    return ans;
}


int main() {

    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    cout << "Intersection Of Two Arrays with Duplicates Elements: ";
    vector<int> res = intersection(a, b);
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";


    return 0;
}
