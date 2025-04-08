// Detect Cycle in a Undirected Graph


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/detect-cycle-in-an-undirected-graph   


#include<bits/stdc++.h>
using namespace std;


bool bfs(int srcNode, vector<vector<int>>& adj, vector<bool>& visit) {
    visit[srcNode] = true;

    queue<pair<int, int>> q; // store <source node, parent node>
    q.push({srcNode, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjNode : adj[node]) {
            if(!visit[adjNode]) {
                visit[adjNode] = true;
                q.push({adjNode, node});
            }
            else if (parent != adjNode) return true;
        }
    }

    return false;
}


// Returns true if the graph contains a cycle, else false.
bool isCycle(int V, vector<vector<int>>& edges) {
    //code here
    vector<vector<int>> adj(V);
    for(auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> visit(V, false);
    for(int i=0; i < V; i++) {
        if(!visit[i]) {
            if (bfs(i, adj, visit)) return true;
        }
    }

    return false;
}




int main() {

    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {3, 4}};

    cout << "Output is ";
    if (isCycle(V, edges)) {
        cout << "True, cycle detected" << endl;
    } else {
        cout << "False, cycle not detected" << endl;
    }


    return 0;
}
