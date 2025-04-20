// Floyd Warshall Algorithm



// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/implementing-floyd-warshall2042   



#include<bits/stdc++.h>
using namespace std;



void floydWarshall(vector<vector<int>> &dist) {
    // Code here
    int V = dist.size();

    for(int via = 0; via < V; via++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][via] != 1e8 && dist[via][j] != 1e8) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }

}



int main() {

    int INF = 1e8;
    vector<vector<int>> dist = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };


    floydWarshall(dist);
    cout << "Output: " << endl;
    for(int i = 0; i<dist.size(); i++) {
        for(int j = 0; j<dist.size(); j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
