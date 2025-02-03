// N-Queens Problem (Printing all solutions in N-Queen Problem)


// Problem-Default-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/n-queen-problem0315  



#include<bits/stdc++.h>
using namespace std;




void solve(int j, int n, vector<vector<int>>& board, vector<int>& sol, 
vector<bool>& col, vector<bool>& ldiag, vector<bool>& rdiag) {
    for(int i=0; i < n; i++) {
        if(j == n) {
            board.push_back(sol);
            return;
        }
        
        if(!col[i] && !ldiag[j-i + n-1] && !rdiag[i+j]) {
            sol.push_back(i+1);
            col[i] = true;
            ldiag[j-i + n-1] = true;
            rdiag[i+j] = true;
            
            solve(j+1, n, board, sol, col, ldiag, rdiag);
            sol.pop_back();
            col[i]=false;
            ldiag[j-i + n-1] = false;
            rdiag[i+j] = false;
        }
    }
}


vector<vector<int>> nQueen(int n) {
    // code here
    vector<bool> col(n, false);
    vector<bool> ldiag(2*n-1, false);
    vector<bool> rdiag(2*n-1, false);
    vector<vector<int>> board;
    vector<int> sol;
    solve(0, n, board, sol, col, ldiag, rdiag);
    return board;
}





int main() {

    int n = 4;
    vector<vector<int>> res = nQueen(n);

    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < n; ++j) {
            cout << res[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << "]\n";
    }


    return 0;
}
