// Maximum Path Sum in a BT


// PRoblem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/maximum-path-sum-from-any-node



#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};




int helperMaxPathSum(Node* root, int& maxi) {
    if(root == nullptr) return 0;

    int lSum = max(0, helperMaxPathSum(root->left, maxi));
    int rSum = max(0, helperMaxPathSum(root->right, maxi));
    maxi = max(maxi, (lSum + rSum + root->data));

    return root->data + max(lSum, rSum);
}

int maxPathSum(Node* root) {
    int maxi = INT_MIN;
    helperMaxPathSum(root, maxi);

    return maxi;
}


int main() {

    // Representation of input binary tree:
    //            10
    //           /  \
    //          2    10
    //         / \     \  
    //        20  1    -25
    //                 /  \
    //                3    4
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << "The Output: " << maxPathSum(root);


    return 0;
}
