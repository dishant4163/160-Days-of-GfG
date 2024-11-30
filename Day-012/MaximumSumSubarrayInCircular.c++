// Maximum Sum Subarray in Circular  



#include<bits/stdc++.h>
using namespace std;

int circularSubarraySum(vector<int> &arr) {
    int totalSum = 0, maxSum = 0, minSum = 0;
    int curMaxSum = arr[0], curMinSum = arr[0];

    for(int i = 0; i < arr.size(); i++) {

        //using kadane's approach to find minimum & maximum sum subarray
        curMaxSum = max(curMaxSum + arr[i], arr[i]);
        maxSum = max(maxSum, curMaxSum);

        curMinSum = min(curMinSum + arr[i], arr[i]);
        minSum = min(minSum, curMinSum);

        totalSum += arr[i];
    }

    int circularSum = totalSum - minSum;

    //If the minimum subarray is equal to total Sum
    //then we just need to return normalSum i.e, maxSum
    if(minSum == totalSum) return maxSum;

    //return ans as maximum sum subarray in circular
    return max(maxSum, circularSum);
}



int main() {

    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << "Maximum Sum Subarray in Circular is: " << circularSubarraySum(arr);


    return 0;
}
