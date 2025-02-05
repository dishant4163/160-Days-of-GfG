// Word Search - Check if a word exists in a grid or not


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/word-search  



#include<bits/stdc++.h>
using namespace std;


bool dfsFindNextMatch(vector<vector<char>>& mat, string& word, int r, int c, int index) {
    int n = mat.size(), m = mat[0].size();
    // if index reaches at end i.e, we have found the word
    if(index == word.size()) return true; // Pattern Matched

    //Out of Boundary
    if(r < 0 || c < 0 || r == n || c == m || 
    mat[r][c] != word[index] || mat[r][c] == '#') return false;

    char dummy = mat[r][c];
    mat[r][c] = '#'; //use special char to mark visited
    // explore all directions recurisevly
    bool up = dfsFindNextMatch(mat, word, r-1, c, index+1);
    bool right = dfsFindNextMatch(mat, word, r, c+1, index+1);
    bool down = dfsFindNextMatch(mat, word, r+1, c, index+1);
    bool left = dfsFindNextMatch(mat, word, r, c-1, index+1);

    //Backtrack i.e, unmark the visited
    mat[r][c] = dummy;

    return up || right || down || left;
}

bool isWordExist(vector<vector<char>>& mat, string& word) {
    // Code here
    int n = mat.size(), m = mat[0].size();

    // if total characyers in mat is less than word length
    if(word.size() > n*m) return false;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            if(mat[row][col] == word[0]) {
                if(dfsFindNextMatch(mat, word, row, col, 0)) return true;
            }
        }
    }
    return false;
}



int main() {

    vector<vector<char>> mat = { {'a', 'x', 'm', 'y'}, 
                                {'b', 'g', 'd', 'f'}, 
                                {'x', 'e', 'e', 't'}, 
                                {'r', 'a', 'k', 's'} };
    string word = "geeks";    
    cout << "The output is: " << (isWordExist(mat, word) ? "true" : "false");


    return 0;
}
