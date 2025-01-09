// Count Pairs With Sum Less Than Target


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-pairs-whose-sum-is-less-than-target   



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countPairs(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1, cnt = 0;

    while(left < right) {
        if(arr[left] + arr[right] < target) {
            cnt += right - left;
            left++;
        }
        else {
            right--;
        }
    }

    return cnt;
}



int main() {

    vector<int> arr = {2, 1, 8, 3, 4, 7, 6, 5};
    int target = 7;
    cout << "Number of pairs with sum less than " << target << " is: " << countPairs(arr, target) << endl;


    return 0;
}
