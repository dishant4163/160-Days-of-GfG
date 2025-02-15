// Check if a BT is BST or Not / Check for BST



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/check-for-bst



#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int v) {
        left = right = nullptr;
    }
};




bool solve(Node* root, int minVal, int maxVal) {
    // base case
    if(!root) return true;

    if(root->data >= maxVal || root->data <= minVal) return false;

    return solve(root->left, minVal, root->data) && solve(root->right, root->data, maxVal);
} 

bool isBST(Node* root) {
    return solve(root, INT_MIN, INT_MAX);
}




int main() {

    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root)) cout << "True" << endl;
    else cout << "False" << endl;


    return 0;
}
