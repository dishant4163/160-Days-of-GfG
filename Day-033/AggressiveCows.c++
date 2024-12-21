// Aggressive Cows


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/aggressive-cows    


#include<bits/stdc++.h>
using namespace std;

bool canWePlaceCows(vector<int>& stalls, int cows, int dist) {
    int cntCows = 1, last = stalls[0];

    for(int i = 1; i < stalls.size(); i++) {
        if(stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows) return true;
    }

    return false;
}


int aggressiveCows(vector<int> &stalls, int k){
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n-1] - stalls[0];
    while(low <= high) {
        int mid = (low + high) >> 1;

        if (canWePlaceCows(stalls, k, mid) == true) low = mid + 1;
        else high = mid - 1;
    }

    return high;
}



int main() {

    vector<int> stalls = {1, 2, 4, 8, 9}; 
    int k = 3;
    int ans = aggressiveCows(stalls, k);
    cout << "The minimum distance between cows, in this case is: " << ans << endl;


    return 0;
}
