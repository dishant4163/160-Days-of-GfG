// Bridge Edge in a Graph / Check if Removing a given Edge Disconnects a Graph


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/bridge-edge-in-graph   



#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &adj, int c, vector<bool>& vis) {
    vis[c] = true;

    for(auto it : adj[c]) {
        if(!vis[it]) {
            dfs(adj, it, vis);
        }
    }
}


bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
    // code here
    vector<vector<int>> adj(V);

    for(auto &edge : edges) {
        // Skip the edge (c, d) or (d, c)
        if((edge[0] == c && edge[1] == d) || (edge[0] == d && edge[1] == c)) {
            continue;
        }

        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> vis(V, false);

    dfs(adj, c, vis);

    return (!vis[d]); // if d is not reachable from (C to bridge)
}



int main() {

    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2,3}};
    int c = 1, d = 2;
    cout << "Output-> " << (isBridge(V, edges, c, d) ? "true" : "false") << endl;


    return 0;
}
