// Alien Dictionary



/*// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/alien-dictionary        

// Code Soln

string findOrder(vector<string> &words) {
    // Initialize variables
    string ans = "";

    vector<vector<int>> graph(26);  // Graph to represent the order of characters
    vector<int> indegree(26, 0);    // Track the number of incoming edges for each node
    vector<bool> vis(26, false);    // Visited array to keep track of characters

    // Mark all characters that appear in the words
    for (string word : words) {
        for (char ch : word) {
            vis[ch - 'a'] = true;
        }
    }

    // Build the graph by comparing adjacent words
    for (int i = 0; i < words.size() - 1; i++) {
        string s1 = words[i];
        string s2 = words[i + 1];

        int len = min(s1.size(), s2.size());

        // If s1 is a prefix of s2 and s1 is longer, it's invalid
        if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) {
            return "";
        }

        // Find the first mismatch between two words
        for (int ptr = 0; ptr < len; ptr++) {
            if (s1[ptr] != s2[ptr]) {
                // Add edge from s1[ptr] -> s2[ptr]
                int u = s1[ptr] - 'a';
                int v = s2[ptr] - 'a';

                // Avoid adding duplicate edges
                if (find(graph[u].begin(), graph[u].end(), v) == graph[u].end()) {
                    graph[u].push_back(v);
                    indegree[v]++;
                }
                break;
            }
        }
    }

    // Topological Sort (Kahn's Algorithm)
    queue<int> q;
    // Add all nodes with no incoming edges (indegree == 0)
    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0 && vis[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Add the current node to the result
        ans += (char)(node + 'a');

        // Process all neighbors
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If the result does not contain all the characters, it means there was a cycle or some characters were not connected
    if (ans.size() != count(vis.begin(), vis.end(), true)) {
        return "";
    }

    return ans;
}


*/



#include<bits/stdc++.h>
using namespace std;



string findOrder(vector<string> &words) {
    // code here
    string ans = "";

    vector<vector<int>> graph(26); // adjacency list
    vector<int> indegree(26, 0); // in-degree of each character
    vector<bool> exists(26, false); // tracks which characters are present

    // mark existing characters
    for(string& word : words) {
        for(char ch : word) {
            exists[ch - 'a'] = true;
        }
    }

    // build the graph from adjacent words
    for(int i = 0; i+1 < words.size(); i++) {
        string w1 = words[i];
        string w2 = words[i+1];
        int len = min(w1.size(), w2.size());
        int j = 0;

        while(j < len && w1[j] == w2[j]) {
            j++;
        }

        if(j < len) {
            int u = w1[j] - 'a';
            int v = w2[j] - 'a';

            graph[u].push_back(v);
            indegree[v]++;
        } else if (w1.size() > w2.size()) {
            return "";
        }
    }

    // topological sort
    queue<int> q;
    for(int i=0; i<26; i++) {
        if(exists[i] && indegree[i] == 0) {
            q.push(i);
        }
    }


    while(!q.empty()) {
        int u = q.front();
        q.pop();

        ans += (char)(u + 'a');

        for(int v : graph[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    //check there was a cycle or not
    for(int i = 0; i < 26; i++) {
        if(exists[i] && indegree[i] != 0) return "";
    }

    return ans;

}




int main() {

    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    string order = findOrder(words);

    cout << "The output is: " << order << endl;


    return 0;
}
