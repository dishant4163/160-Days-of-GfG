// Maximum Product Subarray in a Array


// Problem Link
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/maximum-product-subarray3604  


#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& arr) {
    int n = arr.size(), ans = INT_MIN;
    int prefix = 1, suffix = 1;

    for(int i = 0; i < n; i++) {
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n - i - 1];

        ans = max({ans, prefix, suffix});
    }

    return ans;
}



int main() {

    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout << "The maximum product subarray is: " << maxProductSubArray(arr) << endl;


    return 0;
}
