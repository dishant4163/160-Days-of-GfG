// Trapping Rain Water



// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/trapping-rain-water-1587115621 



#include<iostream>
#include<vector>
using namespace std;


int maxWater(vector<int>& arr) {
    int l = 0, r = arr.size() - 1;
    int maxL = 0, maxR = 0, waterTrap = 0;

    while(l <= r) {
        if(arr[l] <= arr[r]) {
            if(arr[l] >= maxL) {
                maxL = arr[l];
            } else {
                waterTrap += maxL - arr[l];
            }

            l++;
        }
        else {
            if(arr[r] >= maxR) {
                maxR = arr[r];
            } else {
                waterTrap += maxR - arr[r];
            }

            r--;
        }
    }

    return waterTrap;
}



int main() {

    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << "The maximum rain water trapped is: " << maxWater(arr) << endl;


    return 0;
}
