// Level Order Traversal (BFS of Binary Tree)


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/level-order-traversal 



#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    //Calling Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};



vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> ans;
    if(root == nullptr) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        vector<int> level;

        for(int i = 0; i < q.size(); i++) {
            Node* temp = q.front();
            q.pop();

            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }

    return ans;
}



int main() {

    // Create binary tree
    //      1         
    //     / \       
    //    3   2      
    //          \   
    //           4 
    //          /  \
    //         6    5
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(5);

    // Perform level order traversal
    vector<vector<int>> res = levelOrder(root);

    // Print the result
    for (vector<int> level : res)
        for (int data : level)
            cout << data << " ";



    return 0;
}
