// Diameter of a BT


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/diameter-of-binary-tree


#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};




int getHeight(Node* root, int &diameter) {
    if(root == nullptr) return 0;
    
    int leftHt = getHeight(root->left, diameter);
    int rightHt = getHeight(root->right, diameter);
    
    diameter = max(diameter, (leftHt + rightHt));
    
    return 1 + max(leftHt, rightHt);
}

int diameter(Node* root) {
    // Your code here
    int d = 0; 
    getHeight(root, d);
    return d;
}



int main() {

    // Constructed binary tree is
    //          5
    //        /   \
    //       8     6
    //      / \   /
    //     3   7 9

    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(9);
    cout << "The output is: " << diameter(root) << endl;


    return 0;
}
