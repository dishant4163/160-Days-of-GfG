// Minimum cost to connect all houses in a city | MST



// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/minimum-cost-to-connect-all-houses-in-a-city    



#include<bits/stdc++.h>
using namespace std;


int prismAlgo(int v, vector<pair<int, int>> adj[]) {
    int sum = 0;
    vector<int> vis(v, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0,0}); // {weight, node}

    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node] == 1) continue;

        vis[node] = 1;
        sum += wt;

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if(!vis[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return sum;
}

//Soln-1 Solve using Prism's ALgo +  Manhattan Distance 
int minCost1(vector<vector<int>> &houses)  {
    // code here
    int n = houses.size();

    vector<pair<int, int>> adj[n];

    for(int i=0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            // Manhattan Distance 
            int dist = abs(houses[i][0] - houses[j][0]) +
                        abs(houses[i][1] - houses[j][1]);

            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
    }

    return prismAlgo(n, adj);
}









// DSU DS
class DSU {
    vector<int> parent, rank;

    public:
    DSU(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);

        for(int i=0; i <= n; i++) {
            parent[i] =i;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int srcP1 = findParent(u);
        int srcP2 = findParent(v);

        if(srcP1 == srcP2) return;

        if(rank[srcP1] < rank[srcP2]) {
            parent[srcP1] = srcP2;
        } else if(rank[srcP1] > rank[srcP2]) {
            parent[srcP2] = srcP1;
        } else {
            parent[srcP2] = srcP1;
            rank[srcP1]++; 
        }
    }
};



//Soln-2 Solve using Kruskal's Algo + 
int minCost2(vector<vector<int>> &houses)  {
    // code here
    int n = houses.size();

    vector<pair<int, pair<int, int>>> edges;

    for(int i=0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int cost = abs(houses[i][0] - houses[j][0]) + 
                        abs(houses[i][1] - houses[j][1]);

            edges.push_back({cost, {i, j}});
        }
    }

    // Kruskal's Algo
    sort(edges.begin(), edges.end());

    DSU dsu(n);

    int mstCost = 0, edgeVisited = 0;

    for(auto& edge : edges) {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(dsu.findParent(u) != dsu.findParent(v)) {
            dsu.unionByRank(u, v);
            mstCost += wt;
            edgeVisited++; 

            if(edgeVisited == (n-1)) break; // MST complete
        }
    }

    return mstCost;
}






int main() {


    vector<vector<int>> houses = {{0, 7}, {0, 9}, {20, 7}, {30, 7}, {40, 70}};


//Soln-1 Solve using Prism's ALgo
    cout << "'Solve using Prism's ALgo + Manhattan Distance' & output is  " << minCost1(houses) << endl << endl;





//Soln-1 Solve using Kruskal's Algo + Manhattan Distance
cout << "'Solve using Kruskal's Algo + Manhattan Distance' & output is  " << minCost2(houses) << endl << endl;



    return 0;
}

