// Job Sequencing Problem


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/job-sequencing-problem-1587115620   



#include<bits/stdc++.h>
using namespace std;



vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    // code here
    int n = deadline.size();
    vector<int> ans = {0, 0};

    vector<pair<int, int>> jobs;
    for(int i=0; i < n; i++) {
        jobs.push_back({deadline[i], profit[i]});
    }

    sort(begin(jobs), end(jobs));

    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0; i < jobs.size(); i++) {
        if(jobs[i].first > pq.size()) {
            pq.push(jobs[i].second);
        } else if(!pq.empty() && pq.top() < jobs[i].second) {
            pq.pop();
            pq.push(jobs[i].second);
        }
    }

    while(!pq.empty()) {
        ans[1] += pq.top();
        pq.pop();
        ans[0]++;
    }

    return ans;
}



int main() {

    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};
    vector<int> ans = jobSequencing(deadline, profit);
    cout << "Total numbers of jobs completed is " <<ans[0]<<" & " << "Maximum Profit obtained is " <<ans[1];


    return 0;
}
