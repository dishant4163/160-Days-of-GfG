//  Indexes of Subarray Sum


// Problem-Link->
//    



#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target) {
    vector<int> ans;
    int left = 0, right = 0, curSum = 0, n = arr.size();

    while(right < n) {
        curSum += arr[right];

        while(curSum > target && left <= right) {
            curSum -= arr[left];
            left++;
        }

        if(curSum == target) {
            return {left +1, right+1}; //bcz indexing is 1 based
        }

        right++;
    }

    return {-1};
}


int main() {

    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;
    vector<int> result = subarraySum(arr, target);

    if (!result.empty()) {
        cout << "Subarray with sum " << target << " found from index " << result[0] << " to " << result[1] << endl;
    } else {
        cout << "No subarray with sum " << target << " found." << endl;
    }



    return 0;
}
