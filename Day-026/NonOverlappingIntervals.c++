// Non-Overlapping Intervals


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/non-overlapping-intervals  



#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}


int minRemoval(vector<vector<int>> &intervals) {
    //sorting the interals acc. to minimum End time
    sort(intervals.begin(), intervals.end(), compare);

    int cnt = 0, lastEndTime = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] < lastEndTime) cnt++;
        else lastEndTime = intervals[i][1];
    }

    return cnt;
}



int main() {

    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 5}, {1, 4}};
    cout << "Minimum removals required to make ranges Non-Overlapping is: " << minRemoval(intervals) << endl;


    return 0;
}

