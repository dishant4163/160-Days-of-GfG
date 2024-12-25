// Rotate Matrix By 90 degree Anti-ClockWise


// Problem-Link->
//     


#include<bits/stdc++.h>
using namespace std;

void rotateby90(vector<vector<int>>& mat) {
    int n = mat.size();
    // Reverse the each Row of the Matrix
    for(int i=0; i < n; i++) {
        // Row  is mat[i]
        reverse(mat[i].begin(), mat[i].end());
    }

    // Transpose the Matrix
    for(int i=0; i < n; i++) {
        for(int j=0; j < i; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}



int main() {

    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotateby90(mat);
    cout<<"Rotated Matrix is "<<endl;
    for (auto& row : mat) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}