// BFS of Graph


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/bfs-traversal-of-graph   


#include<bits/stdc++.h>
using namespace std;


vector<int> bfs(vector<vector<int>> &adj) {
    // Code here
    vector<int> BFS;
    int srcNode = 0, V = adj.size();

    vector<bool> visit(V, false);

    queue<int> q;

    visit[srcNode] = true;
    q.push(srcNode);

    while(!q.empty()) {
        int curNode = q.front();
        q.pop();

        BFS.push_back(curNode);

        for(auto it : adj[curNode]) {
            if(!visit[it]) {
                visit[it] = true;
                q.push(it);
            }
        }
    }

    return BFS;
}



int main() {

    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    vector<int> ans = bfs(adj);

    cout << "The output is ";
    for(auto i:ans) {
        cout<<i<<" ";
    }


    return 0;
}
