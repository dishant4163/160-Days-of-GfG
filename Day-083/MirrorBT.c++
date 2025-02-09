// Invert BT - Change to Mirror Tree


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/mirror-tree 



#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};



void mirror(Node* root) {
    // Base case 
    if(root == nullptr) return;

    mirror(root->left);
    mirror(root->right);

    // swap left & right SubTree
    swap(root->left, root->right);
}



void levelOrder(Node *root) {
    // Base Case
    if(root == nullptr) {
        cout << "N ";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curNode = q.front();
        q.pop();

        if(curNode == nullptr) {
            cout << "N ";
            return;
        }

        cout << curNode->data << " ";
        q.push(curNode->left);
        q.push(curNode->right);
    }
}



int main() {


    // Input Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


    // Mirror Tree:
    //       1
    //      / \
    //     3   2
    //        / \
    //       5   4


    // Mirror the Tree
    mirror(root);

    // Print Mirrored Binary Tree
    cout << "Mirrored Binary Tree: ";
    levelOrder(root);
    cout << endl;


    return 0;
}
