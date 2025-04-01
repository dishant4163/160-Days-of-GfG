// Activity Selection Problem


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/activity-selection-1587115620   



#include<bits/stdc++.h>
using namespace std;


// Function to solve the activity selection problem
int activitySelection(vector<int> &start, vector<int> &finish) {
    // code here

    int s = start.size(), maxActivity = 0;

    vector<vector<int>> temp;

    for(int i=0; i < s; i++) {
        temp.push_back({finish[i], start[i]});
    }

    sort(begin(temp), end(temp));

    int finishTime = -1, n = temp.size();

    for(int i=0; i < n; i++) {
        if(temp[i][1] > finishTime) {
            finishTime = temp[i][0];
            maxActivity++;
        }
    }

    return maxActivity;
}


int main() {

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << "The output is " << activitySelection(start, finish);


    return 0;
}
