// Set Matrix Rows & Columns To Zeroes



// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/set-matrix-zeroes   



#include<bits/stdc++.h>
using namespace std;

void setMatrixZeroes(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();

    int col0 = 1;
    // Step 1: Traverse the matrix & mark 1st row & col accordingly
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(mat[i][j] == 0) {
                mat[i][0] = 0;

                if(j == 0) col0 = 0;
                else mat[0][j] = 0;
            }
        }
    }

    //Step 2: Mark with 0 from (1,1) to (n-1, m-1)
    for(int i=1; i < n; i++) {
        for(int j=1; j < m; j++) {
            if(mat[i][j] != 0) {
                //Check for col & row
                if(mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
            }
        }
    }

    //Step 3: Finally mark the 1st col & then 1st row
    if(mat[0][0] == 0) {
        for(int j=0; j < m; j++) {
            mat[0][j] = 0;
        }
    }

    if(col0 == 0) {
        for(int i=0; i < n; i++) {
            mat[i][0] = 0;
        }
    }
}


int main() {

    vector<vector<int> > mat = { { 0, 1, 2, 0 }, { 3, 4, 0, 2 }, { 1, 3, 1, 5 } };

    setMatrixZeroes(mat);
    cout << "The set matrix is: " << endl;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}
