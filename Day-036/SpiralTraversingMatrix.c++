// Print Spiral Traversing of Matrix


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/spirally-traversing-a-matrix-1587115621    


#include<bits/stdc++.h>
using namespace std;


vector<int> spirallyTraverse(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size(); // n = no. of rows, m = no. of cols

    vector<int> ans;
    int top = 0, bottom = n-1, left = 0, right = m-1;

    while(top <= bottom && left <= right) {
        // moving Left to Right
        for(int i = left; i <= right; i++) {
            ans.push_back(mat[top][i]);
        }
        top++;

        // moving Top to Bottom
        for(int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        }
        right--;

        // moving Right to Left
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // moving Bottom to Top
        if(left <= right) {
            for(int i=bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
}


int main() {

    vector<vector<int>> mat = {{1, 2, 3, 4}, 
                               {5, 6, 7, 8}, 
                               {9, 10, 11, 12}, 
                               {13, 14, 15, 16}};

    vector<int> res = spirallyTraverse(mat);
    cout << "The output is: ";
    for (int ele : res)
        cout << ele << " ";


    return 0;
}
