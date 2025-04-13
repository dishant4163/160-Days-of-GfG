// Articulation Point - II / Articulation Points (or Cut Vertices) in a Graph



// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/articulation-point2616  



#include<bits/stdc++.h>
using namespace std;



vector<vector<int>> buildAdjList(vector<vector<int>>& edges, int V) {
    vector<vector<int>> adjList(V);

    for(auto& edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    return adjList;
}

void dfs(int node, int parent, vector<int>& tin, vector<int>& low, vector<bool>& vis,
            vector<vector<int>>& adj, int& timer, vector<int>& res) {
    vis[node] = true;
    tin[node] = low[node] = timer++;
    int child = 0;

    for(int it : adj[node]) {
        if(it == parent) continue;

        if(vis[it]) {
            low[node] = min(low[node], tin[it]);
        } else {
            dfs(it, node, tin, low, vis, adj, timer, res);
            low[node] = min(low[node], low[it]);

            if(low[it] >= tin[node] && parent != -1) {
                res[node] = 1;
            }
            child++;
        }
    }

    if(parent == -1 && child > 1) {
        res[node] = 1;
    }
}


vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
    // Code here
    vector<vector<int>> adj = buildAdjList(edges, V);
    vector<int> timeIn(V, -1), lowTime(V, -1), temp(V, 0);
    vector<bool> vis(V, false);
    int timer=0;

    for(int i=0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, -1, timeIn, lowTime, vis, adj, timer, temp);
        }
    }

    vector<int> ans;
    for(int i=0; i < V; i++) {
        if(temp[i]) ans.push_back(i);
    }

    if(ans.empty()) return{-1};

    return ans;
}




int main() {

    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

    vector<int> ans = articulationPoints(V, edges);
    cout << "The output is ";
    for (auto it : ans) {
        cout << it << " ";
    }


    return 0;
}
