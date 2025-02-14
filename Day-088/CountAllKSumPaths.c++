// Count all K Sum Paths in Binary Tree / K Sum Paths


// Problem-Link->  


#include<bits/stdc++.h>
using namespace std;

class Node {
public :
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};



int helperCntPath(Node* root, int k, int curSum, unordered_map<int, int> &preSumMP) {
    if(root == nullptr) return 0;

    int pathCnt = 0;
    curSum += root->data;

    // Pathsum from root to current node is equal to k
    if(curSum == k) pathCnt++;

    // The count of (curSum − k) gives the number of paths 
    // with sum k up to the current node
    pathCnt += preSumMP[curSum - k];

    //Add the current into preSumMap
    preSumMP[curSum]++;

    pathCnt += helperCntPath(root->left, k, curSum, preSumMP);
    pathCnt += helperCntPath(root->right, k, curSum, preSumMP);

    // Remove the current sum from the hashmap
    preSumMP[curSum]--; // Backtrack

    return pathCnt;
}


int countAllPaths(Node* root, int k) {
    unordered_map<int, int> prefixSumMp;
    return helperCntPath(root, k, 0, prefixSumMp);
}




int main() {

    // Create a sample tree:
    //        8
    //      /  \
    //     4    5
    //    / \    \
    //   3   2    2
    //  / \   \
    // 3  -2   1

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(2);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);

    int k = 7; 

    cout << "The output is: " << countAllPaths(root, k) << endl;


    return 0;
}

