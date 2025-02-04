// Algorithm to Solve Sudoku | Sudoku Solver


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/solve-the-sudoku-1587115621     



#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>>& mat, int row, int col, int val) {
    for(int i = 0; i < 9; i++) {
        //check value exists in row
        if(mat[row][i] == val) return false;
        //check value exists in col
        if(mat[i][col] == val) return false;
        //check in each sub-matrix of (3 x 3) is value exists or not
        if(mat[3*(row / 3) + i/3][3*(col/3) + i%3] == val) return false;
    }
    return true;
}

bool solve(vector<vector<int>>& mat) {
    for(int row=0; row < 9; row++) {
        for(int col=0; col < 9; col++) {
            if(mat[row][col] == 0) {
                for(int val = 0; val <= 9; val++) {
                    if(isSafe(mat, row, col, val)) {
                        mat[row][col] = val;
                        if(solve(mat)) return true;
                        else mat[row][col] = 0;
                    }
                }
                // solution not found
                return false;
            }
        }
    }
    // solution found
    return true;
}

void solveSudoku(vector<vector<int>> &mat) {
    solve(mat);
}



int main() {

    vector<vector<int>> mat = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solveSudoku(mat);
    
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }


    return 0;
}
