// Number of Islands



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/find-the-number-of-islands   



#include<bits/stdc++.h>
using namespace std;

void bfs(int r, int c, vector<vector<bool>> &visit, vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();

    visit[r][c] = true;
    queue<pair<int, int>> q;
    q.push({r, c});

    while(!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();

        for(int delR = -1; delR <= 1; delR++) {
            for(int delC = -1; delC <= 1; delC++) {
                int nr = delR + row, nc = delC + col;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 'L' && !visit[nr][nc]) {
                    visit[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
}

int countIslands(vector<vector<char>>& grid) {
    // Code here
    int n = grid.size(), m = grid[0].size(), cnt = 0;

    vector<vector<bool>> visit(n, vector<bool>(m, false));

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(!visit[r][c] && grid[r][c] == 'L') {
                cnt++;
                bfs(r, c, visit, grid);
            }
        }
    }

    return cnt;
}




int main() {

    vector<vector<char>> grid = {   { 'L', 'W', 'W', 'W', 'W' },
                                    { 'W', 'L', 'W', 'W', 'L' },
                                    { 'L', 'W', 'W', 'L', 'L' },
                                    { 'W', 'W', 'W', 'W', 'W' },
                                    { 'L', 'W', 'L', 'L', 'W' } };

    cout << "The output is " << countIslands(grid) << endl;



    return 0;
}
