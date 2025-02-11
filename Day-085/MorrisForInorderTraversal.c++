// Inorder Traversal (Morris Traversal)



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/inorder-traversal    




#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};




vector<int> inOrder(Node* root) {
    vector<int> ans;
    Node* cur = root;

    while(cur != nullptr) {
        if(cur->left == NULL) {
            ans.push_back(cur->data);
            cur = cur->right;
        } else {
            Node* prev = cur->left;
            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                ans.push_back(cur->data);
                cur = cur->right;
            }
        }
    }

    return ans;
}



int main() {

    // Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //        / \  
    //       4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = inOrder(root);
    cout << "Morris Inorder Traversal is: " << endl;
    for (int data : res) {
        cout << data << " ";
    }
    
    return 0;
}
