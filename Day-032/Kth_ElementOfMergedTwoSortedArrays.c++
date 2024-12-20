// K-th Element of Merged Two Sorted Arrays


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/k-th-element-of-two-sorted-array1317      


#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k) {
    int m = a.size(), n = b.size();

    if(m > n) return kthElement(b, a, k);

    int low = max(0, k-n), high = min(k, m);

    while(low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = k - mid1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
        if(mid1 < m) r1 = a[mid1];
        if(mid2 < n) r2 = b[mid2];

        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if(l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return 0;
}


int main() {

    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << "The K-th Element of merged 2 sorted arrays is: " << kthElement(a, b, k);

    return 0;
}
