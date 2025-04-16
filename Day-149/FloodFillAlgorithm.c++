// Flood Fill Algorithm



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/flood-fill-algorithm1856       




#include<bits/stdc++.h>
using namespace std;


// Solving using BFS
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Code here
    int n = image.size(), m = image[0].size();

    if(image[sr][sc] == newColor) return image;

    queue<pair<int, int>> q;
    q.push({sr, sc});

    int initialColor  = image[sr][sc];
    image[sr][sc] = newColor; // change color of the starting pixel

    int deltaR[] = {-1, 0, 1, 0};
    int deltaC[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        //traverse in all 4 directions
        for(int i = 0; i < 4; i++) {
            int newR = r + deltaR[i];
            int newC = c + deltaC[i];

            if(newR >= 0 && newR < n && newC >= 0 && newC < m && image[newR][newC] == initialColor) {
                image[newR][newC] = newColor;
                q.push({newR, newC});
            }
        }
    }

    return image;
}



int main() {

    // Define the input 2D image (grid of pixel colors)
    vector<vector<int>> image = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };

    // Starting pixel coordinates (row = 1, column = 2)
    int sr = 1, sc = 2;

    // New color to apply to the connected region
    int newColor = 2;

    // Call the floodFill function to perform DFS/BFS fill from the
    // starting pixel
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "Output -> " << endl;

    // Print the updated image after flood fill
    for (auto& row : result) {
        for (auto& pixel : row) {
            // Print each pixel with a space
            cout << pixel << " ";  
        }
        // Move to the next line after printing each row
        cout << "\n";  
    }


    return 0; 
}