// Merge K Sorted Linked Lists


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/merge-k-sorted-linked-lists


#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};


//WHY solve using Heap(minHeap) ?
  // bcz It works better for UnEqual Sized Lists

class compare {
public:
    bool operator() (Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*>& arr) {
    // Your code here
    int k = arr.size();

    //decalre MinHeap
    priority_queue<Node*, vector<Node*>, compare>  minHeap;

    // Base Case
    if(k == 0) return nullptr;

    for(int i = 0; i < k; i++) {
        if(arr[i]) minHeap.push(arr[i]); 
    }

    Node *head = nullptr, *tail = nullptr;

    while(!minHeap.empty()) {
        Node* topNode = minHeap.top();
        minHeap.pop();

        if(topNode->next != NULL) {
            minHeap.push(topNode->next);
        }

        if(head == NULL) { // answer LL is empty
            head = topNode;
            tail = topNode;
        }
        else { // insert at LL
            tail->next = topNode;
            tail = topNode;
        }
    }

    return head;
}



// Function to print nodes in a given LL
void printList(Node* root) {
    while(root != nullptr) {
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}


int main() {
    int k = 3; 
    vector<Node*> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    
    Node* head = mergeKLists(arr);

    cout << "The output is: ";
    printList(head);

    return 0;
}
