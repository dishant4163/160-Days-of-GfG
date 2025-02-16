// k-th Smallest in BST


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/find-k-th-smallest-element-in-bst



#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};



int kthSmallEleInOr(Node* root, int k, int &cnt) {
    // Base case
    if(!root || cnt >= k) return -1;

    // Left Subtree
    int Left = kthSmallEleInOr(root->left, k, cnt);

    // if Kth smallest found in left subtree
    // then return 
    if(Left != -1) return Left;

    //increment the node / move to next node
    cnt++;

    // if current node is smallest node
    if(cnt == k) return root->data;

    //else right subtree have kth smallest then return its value
    int Right = kthSmallEleInOr(root->right, k, cnt);
    return Right;
}

int kthSmallest(Node *root, int k) {
    int count = 0;
    return kthSmallEleInOr(root, k, count);
}


int main() {

    // Binary search tree
    //      20
    //    /   \
    //   8     22
    //  / \
    // 4   12
    //    /  \
    //   10   14
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    int k = 3;

    cout << "The output is: " << kthSmallest(root, k) << endl;
    return 0;

}
