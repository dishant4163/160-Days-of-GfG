// Maximum Subarray Sum - Kadane's Algorithm  



#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int>& arr) {
    int n = arr.size();
    int sum = 0, maxi = arr[0];

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        maxi = max(sum, maxi);

        if(sum < 0) sum = 0;
    }

    return maxi;
}


int main() {

    vector<int> arr = {-2, -4};
    cout << maxSubarraySum(arr);

    return 0;
}
