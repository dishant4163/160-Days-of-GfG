// Minimum Platforms / Minimum Platforms Required for Given Arrival and Departure Times



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/minimum-platforms-1587115620    


#include<bits/stdc++.h>
using namespace std;


int minPlatform(vector<int> &arr, vector<int>& dep) {
    // code here
    sort(begin(arr), end(arr));
    sort(begin(dep), end(dep));

    int n = arr.size();

    int i=0, j=0, maxCnt=0, cnt=0;

    while(i < n && j < n) {
        if(arr[i] <= dep[j]) {
            cnt++;
            i++;
        } else {
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt, cnt);
    }

    return maxCnt;
}



int main() {

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "The output is " << minPlatform(arr, dep);


    return 0;
}
