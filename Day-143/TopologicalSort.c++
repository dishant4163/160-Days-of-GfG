// Topological Sort


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/topological-sort   



#include<bits/stdc++.h>
using namespace std;


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj, stack<int>& st) {
    vis[node] = true;

    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}



vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    vector<int> ans;

    vector<vector<int>> adj(V);
    for(auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<bool> vis(V, false);
    stack<int> st;

    for(int i=0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}



int main() {

    // Graph represented as an adjacency list
    int v = 6;
    vector<vector<int>> edges = {{2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}};

    vector<int> ans = topoSort(v, edges);

    cout << "The output is ";
    for (auto node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
