// Rotten Oranges - Minimum Time to Rot all



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/rotten-oranges2536   



#include<bits/stdc++.h>
using namespace std;



int orangesRotting(vector<vector<int>>& mat) {
    // code here
    int n = mat.size(), m = mat[0].size();

    queue<pair<pair<int, int>, int>> q;
    int cntFresh = 0, visit[n][m];

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(mat[i][j] == 2) {
                q.push({{i,j}, 0});
                visit[i][j] = 2;
            }
            else {
                visit[i][j] = 0;
            }

            if(mat[i][j] == 1) cntFresh++;
        }
    }

    int maxTime = 0, cntRotten = 0;
    int deltaR[] = {-1, 0, 1, 0};
    int deltaC[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;

        q.pop();

        maxTime = max(t, maxTime);

        for(int i=0; i < 4; i++) {
            int newR = r + deltaR[i];
            int newC = c + deltaC[i];

            if(newR >= 0 && newR < n && newC >= 0 && newC < m && 
            visit[newR][newC] == 0 && mat[newR][newC] == 1) {
                q.push({{newR, newC}, t+1});
                visit[newR][newC] = 2;
                cntRotten++;
            }
        }
    }

    if(cntFresh != cntRotten) return -1;

    return maxTime;
}



int main() {

    vector<vector<int>> mat = {{2, 1, 0, 2, 1}, {1, 0, 1, 2, 1}, {1, 0, 0, 2, 1}};
    cout << "The output is " << orangesRotting(mat);


    return 0;
}
