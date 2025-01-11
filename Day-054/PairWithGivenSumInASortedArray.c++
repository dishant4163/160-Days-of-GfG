// 2 Sum - Count Pair with given Sum in a Sorted Array


// Problem Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-with-given-sum-in-a-sorted-array4940   



#include<iostream>
#include<vector>

using namespace std;


int countPairs(vector<int> &arr, int target) {
    int l=0, r = arr.size() - 1, count = 0;

    while(l < r) {
        int sum = arr[l] + arr[r];
        if (sum < target) l++;
        else if (sum > target) r--;

        else {
            int cnt1 = 0, cnt2 = 0, ele1 = arr[l], ele2 = arr[r];

            while(l <= r && arr[l] == ele1) {
                l++;
                cnt1++;
            }

            while(l <= r && arr[r] == ele2) {
                r--;
                cnt2++;
            }

            if(ele1 == ele2) 
                count += (cnt1 * (cnt1 - 1)) / 2;
            else count += (cnt1 * cnt2);
        }
    }

    return count;
}

int main() {

    vector<int> arr = {-1, 1, 5, 5, 7};
    int target = 6;

    cout <<"Count of pair with the given sum " << target << " is: " << countPairs(arr, target);

    return 0;
}
