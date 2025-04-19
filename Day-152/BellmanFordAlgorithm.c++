// Bellman Ford Algorithm



// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/distance-from-the-source-bellman-ford-algorithm     



#include<bits/stdc++.h>
using namespace std;



vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    //code here
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    //Do relaxation for exactly (V-1) times
    for(int i = 0; i < V; i++) {
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = wt + dist[u];
            }
        }
    }

    //Nth relaxation to check negative cycle
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1}; //-ve cycle detected
        }
    }

    return dist;
}




int main() {

    // Number of vertices in the graph
    int V = 5;

    // Edge list representation: {source, destination, weight}
    vector<vector<int>> edges = {
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };

    // Define the source vertex
    int src = 0;

    // Run Bellman-Ford algorithm to get shortest paths from src
    vector<int> ans = bellmanFord(V, edges, src);

    // Output the shortest distances from src to all vertices
    cout << "The output is ";
    for (int dist : ans) 
        cout << dist << " ";


    return 0;
}
