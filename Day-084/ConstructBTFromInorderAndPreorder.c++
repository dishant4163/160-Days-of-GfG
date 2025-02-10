// Construct Tree from given Inorder and Preorder traversals


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/construct-tree-1


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




Node* help2BuildBT(map<int, int>& inMap, vector<int>& preO, int preStart, int preEnd, vector<int>& inO, int inStart, int inEnd) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    Node* root = new Node(preO[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = help2BuildBT(inMap, preO, preStart+1, preStart + numsLeft, inO, inStart, inRoot - 1);
    root->right = help2BuildBT(inMap, preO, preStart+1+numsLeft, preEnd, inO, inRoot+1, inEnd);

    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
    map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    Node* root = help2BuildBT(inMap, preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    return root;
}




// Print tree as level order
void printLevelOrder(Node *root) {
    if (root == nullptr) {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}


int main() {

    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    Node *root = buildTree(inorder, preorder);

    printLevelOrder(root);


    return 0;
}
