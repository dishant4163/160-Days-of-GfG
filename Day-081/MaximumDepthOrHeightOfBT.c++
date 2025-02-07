// Maximum Depth of a BT / Height of BT


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/height-of-binary-tree



#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;
    
        Node(int val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
};



int height(Node* node) {
    // code here
    int ht = 0;
    if(node == nullptr) return ht;
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty()) {
        ht++;
        int n = q.size();
        for(int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
    return ht - 1;
}



int main() {

    // Representation of the input tree:
    //     12
    //    /  \
    //   8   18
    //  / \
    // 5   11
    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);
    
    cout << "The output is: " << height(root);


    return 0;
}
