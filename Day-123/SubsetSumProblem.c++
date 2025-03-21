// Subset Sum Problem


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/subset-sum-problem-1611555638  


#include<bits/stdc++.h>
using namespace std;


bool isSubsetSum(vector<int>& arr, int sum) {
    // code here
    int n = arr.size();
    vector<bool> prev(sum + 1, false), cur(sum+1, false);

    prev[0] = true;

    if(arr[0] <= sum) prev[arr[0]] = true;

    for(int i = 1; i < n; i++) {
        cur[0] = true;
        for(int tar = 1; tar <= sum; tar++) {
            bool take = false;
            bool notTake = prev[tar];

            if(arr[i] <= tar) {
                take = prev[tar - arr[i]];
            }

            cur[tar] = take || notTake;
        }
        prev = cur;
    }
    return prev[sum];
}

int main() {

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    cout << "The output is: ";

    if (isSubsetSum(arr, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    return 0;
}
