// Two sum in BST - Pair Sum in BST


// Problem Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/find-a-pair-with-given-target-in-bst


#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, * right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


void inorderTraversal(Node* root, vector<int>& inorder) {
    if(!root) return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}


bool findTarget(Node *root, int target) {
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int l = 0, r = inorder.size() - 1;

    while(l < r) {
        int sum = inorder[l] + inorder[r];

        if(sum == target) {
            return true;
        }
        else if (sum < target) {
            l++;
        }
        else r--;
    }

    return false;
}




int main() {

    // Constructing the following BST:
    //         7
    //        / \
    //       3   8
    //      / \   \
    //     2   4   9

    Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);

    int target = 12;

    // Check if there are two elements in the BST
    // that added to "target"
    if (findTarget(root, target)) cout << "True";
    else cout << "False";

    return 0;
}
