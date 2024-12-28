// Search Element in a Sorted Matrix


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-matrix-1587115621   


#include<bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n = mat.size(), m = mat[0].size();

    int low = 0, high = n * m -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int row = mid / m, col = mid % m;

        if(mat[row][col] == x) return true;

        if(mat[row][col] < x) low = mid + 1;
        else high = mid - 1;
    }

    return false;
}


int main() {

    vector<vector<int>> mat = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}
