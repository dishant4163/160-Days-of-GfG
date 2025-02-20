// Serialize and Deserialize a BT


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/serialize-and-deserialize-a-binary-tree



#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int v) {
        data = v;
        left = right = nullptr;
    }
};




// Function to serialize a tree and return a list containing nodes of tree.
vector<int> serialize(Node *root) {
    // Your code here
    vector<int> ans;
    if(!root) return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* cur = q.front();
        q.pop();
        
        if(cur == nullptr) ans.push_back(-1);
        else ans.push_back(cur->data);
        if(cur != nullptr) {
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return ans;
}

// Function to deserialize a list and construct the tree.
Node *deSerialize(vector<int> &arr) {
    // Your code here
    if(arr.empty()) return nullptr;
    if(arr[0] == -1 ) return nullptr;
    
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    
    while(i < arr.size() && !q.empty()) {
        Node* cur = q.front();
        q.pop();
        
        // Left Child
        if(i < arr.size() && arr[i] != -1) {
            Node* Left = new Node(arr[i]);
            cur->left = Left;
            q.push(Left);
        }
        i++;
        
        // Right Child
        if(i < arr.size() && arr[i] != -1) {
            Node* Right = new Node(arr[i]);
            cur->right = Right;
            q.push(Right);
        }
        i++;
    }
    
    return root;
}







//Driver Code Starts{
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

    // Create a hard coded tree
    //       10
    //     /    \
    //    20    30
    //  /   \
    // 40  60
    Node* root = new Node(10);        
    root->left = new Node(20);        
    root->right = new Node(30);       
    root->left->left = new Node(40);
    root->left->right = new Node(60); 
    
    vector<int> arr = serialize(root);
    Node* res = deSerialize(arr);

    cout << "The output is: ";
    printLevelOrder(res);


    return 0;
}

//Driver Code Ends }
