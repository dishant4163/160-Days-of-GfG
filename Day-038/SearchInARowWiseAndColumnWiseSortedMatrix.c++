// Search In A Row-wise & Column-Wise Sorted Matrix


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-matrix17201720


#include<bits/stdc++.h>
using namespace std;

bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
        int row = 0, col = m-1;
        
        while(row < n && col >= 0) {
            if(mat[row][col] == x) return true;
            else if (mat[row][col] < x) row++;
            else col--;
        }
        
        return false;
}


int main() {

    vector<vector<int>> mat = {{3, 30, 38},
                               {20, 52, 54},
                               {35, 60, 69}};
    int x = 35;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";


    return 0;
}
