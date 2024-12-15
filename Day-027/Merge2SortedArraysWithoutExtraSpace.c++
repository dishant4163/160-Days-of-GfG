// Merge Two Sorted Arrays Without Extra Space


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/merge-two-sorted-arrays-1587115620     


#include<bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int left = n-1, right = 0;

    while(left >= 0 && right < m) {
        if(a[left] > b[right]) {
            swap(a[left], b[right]);
            left--; 
            right++;
        }
        else break;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}




int main() {

    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};
    mergeArrays(a, b);

    for (int ele: a)
        cout << ele << " ";
    cout << "\n";
    for (int ele: b)
        cout << ele << " ";


    return 0;
}
