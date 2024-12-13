// Insert & Merge Intervals



// Problem-Link-> 
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/insert-interval-1666733333  


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int> &newInterval) {
    vector<vector<int>> ans;

    int n = intervals.size(), i = 0;

    while(i < n && intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
    }

    while(i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);

    while(i < n) {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}




int main() {

    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    
    vector<vector<int>> ans = insertInterval(intervals, newInterval);
    cout << "The output for newInsert & Merge Intervals is: " << endl;
    for (vector<int> it: ans) {
        cout << it[0] << " " << it[1] << endl;
    }


    return 0;
}
