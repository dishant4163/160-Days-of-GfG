// Recover BST - Two Nodes are swapped / Fixing Two Nodes of a BST



// Promblem Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/fixed-two-nodes-of-a-bst



#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};




// Recursive Function for inorder traversal 
// to find out  the two swapped nodes.
void inorderCorrectBST(Node* root, Node* &first, Node* &middle, Node* &last, Node* &prev) {
    // Base Case
    if(!root) return;

    inorderCorrectBST(root->left, first, middle, last, prev);

    // If this node is smaller than the previous node, 
    // it's violating the BST rule.
    if(prev != NULL && root->data < prev->data) {
        // If this is the first violation, mark these 
        // two nodes as 'first' and 'middle'
        if(first == NULL) {
            first = prev;
            middle = root;
        }
        // If this is the second violation, 
        // mark this node as last
        else last = root;
    }

    // Mark this node as previous
    prev = root;

    inorderCorrectBST(root->right, first, middle, last, prev);
}


// Function to fix the given BST, where two nodes are swapped.
void correctBST(Node *root) {
    Node *first = nullptr, *middle = nullptr, *last = nullptr;
    Node *prev = new Node(INT_MIN);

    inorderCorrectBST(root, first, middle, last, prev);

    if(first && last) swap(first->data, last->data);
    else if(first && middle) swap(first->data, middle->data);
}




//Driver Code Starts
// Inorder traversal function to print tree in sorted order
void inorderTraversal(Node *root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main(){
    // Constructing the tree with swapped nodes
    //       6
    //     /  \
    //    10   2
    //   / \  / \
    //  1  3 7  12
    // Here, 10 and 2 are swapped

    Node *root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    cout << "The output is: ";
    correctBST(root);
    inorderTraversal(root);  // Perform inorder traversal to print the result

    return 0;
}
// Driver Code Ends
