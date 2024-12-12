// Merge Overlapping Intervals


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/overlapping-intervals--170633  


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    //sort the given intervals
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i = 0; i < arr.size(); i++) {
        // if the current interval does not lie in the last interval
        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        } 
        // if the current interval lies in the last interval
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}




int main() {

    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    vector<vector<int>> res = mergeOverlap(arr);
    cout << "The merged intervals are: " ;
    for (auto it : res) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;


    return 0;
}
