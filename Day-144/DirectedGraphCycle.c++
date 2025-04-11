// Detect Cycle in Directed Graph / Directed Graph Cycle
// Kahn’s Algorithm (Topological Sort via BFS)



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/detect-cycle-in-a-directed-graph  



#include<bits/stdc++.h>
using namespace std;



vector<vector<int>> buildAdjList(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);

    for(auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    return adj;
}


bool isCyclic(int V, vector<vector<int>> &edges) {
    // code here
    vector<vector<int>> adj = buildAdjList(V, edges);

    int indegree[V] = {0};
    for(int i = 0; i < V; i++) {
        for(auto neighbour : adj[i]) {
            indegree[neighbour]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
    
        count++;

        for(auto neighbourNode : adj[node]) {
            indegree[neighbourNode]--;
            if(indegree[neighbourNode] == 0) {
                q.push(neighbourNode);
            }
        }
    }

    return (count == V) ? false : true;
}



int main() {

    int V = 4; // Number of vertices
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};

    // Output: true (cycle exists)
    cout << "The output is " << (isCyclic(V, edges) ? "true" : "false") << endl;


    return 0;
}
