// Dijkstras Algo


// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/implementing-dijkstra-set-1-adjacency-matrix  


#include<bits/stdc++.h>
using namespace std;


// constructing adjacency list
vector<vector<vector<int>>> buildAdjList(int V, vector<vector<int>> &edges) {
    vector<vector<vector<int>>> adj(V);

    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    return adj;
}



vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // Code here

    vector<vector<vector<int>>> adj = buildAdjList(V, edges);
    vector<int> miniDist(V, 1e9);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0, src});
    miniDist[src] = 0;

    while(!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWt = it[1];

            if(dist + edgeWt < miniDist[adjNode]) {
                miniDist[adjNode] = dist + edgeWt;
                pq.push({miniDist[adjNode], adjNode});
            }
        }
    }

    return miniDist;
}




int main() {

    int V = 5;
    int src = 0;

    // edge list format: {u, v, weight}
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, 
                                {2, 3, 2}, {3, 4, 10}};

    vector<int> result = dijkstra(V, edges, src);

    cout << "The output is ";
    // Print shortest distances in one line
    for (int dist : result)
        cout << dist << " ";

    return 0;
}