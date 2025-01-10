// 2 Sum - Pair Sum Closest to Target


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-in-array-whose-sum-is-closest-to-x1124   



#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


vector<int> sumClosest(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());

    int n = arr.size(), miniDiff = INT_MAX;
    vector<int> ans;
    int left = 0, right = n-1;

    while(left < right) {
        int currSum = arr[left] + arr[right];

        if (abs(target - currSum) < miniDiff) {
            miniDiff = abs(target - currSum);
            ans = {arr[left], arr[right]};
        } 

        if (currSum < target) left++;
        else if(currSum > target) right--;
        else return ans;
    }

    return ans;
}


int main() {

    vector<int> arr = {5, 2, 7, 1, 4};
    int target = 10;

    vector<int> res = sumClosest(arr, target);
    cout << "Pair Sum Closest to Target is: " ;
    if(res.size() > 0)
        cout << res[0] << " " << res[1];


    return 0;
}
