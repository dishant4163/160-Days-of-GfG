// Boundary Traversal of Binary Tree


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/boundary-traversal-of-binary-tree 



#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};




bool isLeaf(Node* root) {
    return (!root->left && !root->right);
}

void addLeft(Node* root, vector<int>& v) {
    Node* cur = root->left;
    while(cur) {
        if(!isLeaf(cur)) {
            v.push_back(cur->data);
        }
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRight(Node* root, vector<int>& v) {
    Node* cur = root->right;
    vector<int> temp;
    while(cur) {
        if(!isLeaf(cur)) {
            temp.push_back(cur->data);
        }
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    
    for(int i = temp.size()-1; i >= 0; i--){
        v.push_back(temp[i]);
    }
}

void addLeaves(Node* root, vector<int>& v) {
    if(isLeaf(root)) {
        v.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, v);
    if(root->right) addLeaves(root->right, v);
}



vector<int> boundaryTraversal(Node *root) {
    vector<int> ans;
    if(!root) return ans;

    if(!isLeaf(root)) ans.push_back(root->data);

    addLeft(root, ans);
    addLeaves(root, ans);
    addRight(root, ans);

    return ans;
}




int main() {

    // Hardcoded Binary tree
    //        20
    //       /  \
    //      8    22
    //     / \     \
    //    4   12    25
    //       /  \
    //      10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);

    vector<int> boundary = boundaryTraversal(root);

    for (int x : boundary)
        cout << x << " ";

    return 0;
}
