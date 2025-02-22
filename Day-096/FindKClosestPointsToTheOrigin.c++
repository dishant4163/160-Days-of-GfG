// Find K Closest Points to the Origin


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/k-closest-points-to-origin--172242



#include<bits/stdc++.h>
using namespace std;

// Function to calculate squared distance from the origin
int sqauredDist(vector<int>& point) {
    return point[0]*point[0] + point[1]*point[1];
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int n = points.size();
    // Declare MAX-HEAP
    priority_queue<pair<int, vector<int>>> maxHeap;

    for(int i = 0; i < n; i++) {
        int dist = sqauredDist(points[i]);

        if(maxHeap.size() < k) {
            // if heap size is less than k, insert the point
            maxHeap.push({dist, points[i]});
        }
        else {
            // if heap size is k, compare with top element
            if(dist < maxHeap.top().first) {
                // replace the top element if current point is closer
                maxHeap.pop();
                maxHeap.push({dist, points[i]});
            }
            // else ignore the current point
        }
    }

    vector<vector<int>> ans;
    // Take the k closest points from the heap
    while(!maxHeap.empty()) {
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return ans;
}



int main() {

    vector<vector<int>> points = {{1, 3}, {-2, 2}, 
                                    {5, -1}, {3, 2}, {1, 1}};
    int k = 3;

    vector<vector<int>> res = kClosest(points, k);
    cout << "The output is : ";
    for (vector<int>point : res) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }

    return 0;


    return 0;
}
