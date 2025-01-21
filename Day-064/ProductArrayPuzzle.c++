// Product Array Puzzle / Product Array Except Self



// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/product-array-puzzle4525   


#include<bits/stdc++.h>
using namespace std;


vector<int> productExceptSelf(vector<int> &arr) {
    int zeros = 0, n = arr.size();
    int index = -1, prod = 1;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            zeros++;
            index = i;
        } else {
            prod *= arr[i];
        }
    }

    vector<int> ans(n, 0);

    if(zeros == 0) {
        for(int i = 0; i < n; i++) {
            ans[i] = prod / arr[i];
        }
    }
    else if (zeros == 1) {
        ans[index] = prod;
    }

    return ans;
}


int main() {

    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf(arr);
    cout << "The output is: ";
    for (int val : res) {
        cout << val << " ";        
    }



    return 0;
}
