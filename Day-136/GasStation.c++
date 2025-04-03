// Gas Station


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/circular-tour-1587115620  



#include<bits/stdc++.h>
using namespace std;


int startStation(vector<int> &gas, vector<int> &cost) {
    // Your code here
    int n = gas.size();

    int curGas = 0, startInd = 0;

    for(int i =0; i < n; i++) {
        curGas = curGas + gas[i] - cost[i];

        if(curGas < 0) {
            startInd = i+1;
            curGas = 0;
        }
    }

    curGas = 0;
    for(int i = 0; i < n; i++) {
        int circularInd = (i + startInd) % n;
        curGas = curGas + gas[circularInd] - cost[circularInd];

        if(curGas < 0) return -1;
    }

    return startInd;
}



int main() {

    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << "The output is " << startStation(gas, cost) << endl;


    return 0;
}
