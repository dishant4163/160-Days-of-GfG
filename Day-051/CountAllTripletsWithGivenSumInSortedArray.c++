// 3 Sum - Count Triplets With Given Sum In Sorted Array


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-all-triplets-with-given-sum-in-sorted-array



#include<iostream>
#include<vector>
using namespace std;

int countTriplets(vector<int> &arr, int target) {
    int n = arr.size(), tripletCnt = 0;

    if(n < 3) return 0;

    for(int i=0; i < n-2; i++) {
        int left = i+1, right = n-1;

        while(left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if(sum < target) left++;
            else if (sum > target) right--;

            else if(sum == target) {
                int ele1 = arr[left], ele2 = arr[right], cnt1 = 0, cnt2 = 0;

                while(left <= right && arr[left] == ele1) {
                    left++;
                    cnt1++;
                }

                while(left <= right && arr[right] == ele2) {
                    right--;
                    cnt2++;
                }

                if(ele1 == ele2)
                    tripletCnt += (cnt1 * (cnt1 - 1)) / 2;

                else 
                    tripletCnt += (cnt1 * cnt2);
            }
        }
    }

    return tripletCnt;
}



int main() {

    vector<int> arr = {-3, -1, -1, 0, 1, 2};
    int target = -2;

    cout << "Number of triplets with given sum = " << target << " is: " << countTriplets(arr, target) << endl;


    return 0;
}
