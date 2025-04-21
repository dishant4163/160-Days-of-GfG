// Find Minimum Weight Cycle in an Undirected Graph



// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/minimum-weight-cycle  


#include<bits/stdc++.h>
using namespace std;



vector<vector<vector<int>>> buildAdj(int V, vector<vector<int>>& edges) {
    vector<vector<vector<int>>> adj(V);

    for(auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    return adj;
}


int helpShortestPath(int V, vector<vector<vector<int>>>& adj, int src, int dest) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
    pq.push({0, src});

    while(!pq.empty()) {
        pair<int, int> Top = pq.top();
        pq.pop();

        int minDist = Top.first;
        int u = Top.second;

        if(minDist > dist[u]) continue;

        for(auto& neighbor : adj[u]) {
            int v = neighbor[0];
            int wt = neighbor[1];

            // skip the ignored edge
            if ((u == src && v == dest) || (u == dest && v == src)) continue;

            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[dest];
}


// Function to find the minimum weight cycle in the graph
int findMinCycle(int V, vector<vector<int>>& edges) {
    //Code here
    vector<vector<vector<int>>> adj = buildAdj(V, edges);
    int minCycle = INT_MAX;

    for(const auto& edge : edges) {
        int dist = helpShortestPath(V, adj, edge[0], edge[1]);

        if(dist != INT_MAX) {
            minCycle = min(minCycle, dist + edge[2]);
        }
    }

    return minCycle;
}



int main() {

    int V = 5;

    vector<vector<int>> edges = {{0, 1, 2}, 
                                 {1, 2, 2}, 
                                 {1, 3, 1}, 
                                 {1, 4, 1}, 
                                 {0, 4, 3}, 
                                 {2, 3, 4}};

    cout << "The output is  " << findMinCycle(V, edges) << endl;


    return 0;
}
