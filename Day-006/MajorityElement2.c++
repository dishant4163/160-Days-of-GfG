// Majority Element II - Elements occurring more than ⌊N/3⌋ times

//Problem Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/majority-vote  


#include<bits/stdc++.h>
using namespace std;

vector<int> findMajority(vector<int>& arr) {
    // Your code goes here.
    int n = arr.size(), el1 = -1, el2 = -1, cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < n; i++) {
        if(cnt1 == 0 && arr[i] != el2) {
            cnt1++;
            el1 = arr[i];
        }
        else if(cnt2 == 0 && arr[i] != el1) {
            cnt2++;
            el2 = arr[i];
        }
        else if(el1 == arr[i]) cnt1++;
        else if(el2 == arr[i]) cnt2++;
        else {
            cnt1--; cnt2--;
        }
    }

    vector<int> ans;
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0; i < n; i++) {
        if(el1 == arr[i]) cnt1++;
        if(el2 == arr[i]) cnt2++;
    }

    if(cnt1 > n/3) ans.push_back(el1);
    if(cnt2 > n/3) ans.push_back(el2);

    sort(ans.begin(), ans.end());

    return ans;
}


int main() {

    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for (int ele : res) {
        cout << ele << " ";
    }
    return 0;
}
