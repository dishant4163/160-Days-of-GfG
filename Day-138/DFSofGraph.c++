// DFS of Graph



// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/depth-first-traversal-for-a-graph    



#include<bits/stdc++.h>
using namespace std;


void dfsHelper(vector<vector<int>>& adj, vector<bool>& vis, int node, vector<int>& ans) {
    vis[node] = true;
    ans.push_back(node);

    for(int it : adj[node]) {
        if(!vis[it]) {
            dfsHelper(adj, vis, it, ans);
        }
    }
}

// Main DFS function to perform DFS for the entire graph
vector<int> DFS(vector<vector<int>>& adj) {
    vector<int> ans;
    vector<bool> vis(adj.size(), false);

    for(int i=0; i < adj.size(); i++) {
        if(!vis[i]) {
            dfsHelper(adj, vis, i, ans);
        }
    }

    return ans;
}






void addEdge(vector<vector<int>> &adj, int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main() {

    int V = 6;
    // Create an adjacency list for the graph
    vector<vector<int>> adj(V);

    // Define the edges of the graph
    vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};

    // Populate the adjacency list with edges
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);
    vector<int> res = DFS(adj);

    cout << "The output is " ;
    for (auto it : res)
        cout << it << " ";


    return 0;
}
