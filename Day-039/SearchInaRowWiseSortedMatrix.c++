// Search in Row-Wise Sorted Matrix



// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-row-wise-sorted-matrix


#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& arr, int x) {
    int low = 0, high = arr.size();

    while(low <= high) {
        int mid = low + (high - low) /2;

        if(x == arr[mid]) return true;

        if(x < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }

    return false;
}


bool searchRowMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size();

    for(int i=0; i < n; i++) {
        if(search(mat[i], x)) return true;
    }

    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 4, 9},
                               {2, 5, 6},
                               {9, 25, 27}};
    int x = 9;
    if(searchRowMatrix(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}
