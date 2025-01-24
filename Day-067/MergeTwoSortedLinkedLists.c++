// Merge Two Sorted Linked Lists





#include<bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


Node* sortedMerge(Node* head1, Node* head2) {
    // Base Cases
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while(head1 != nullptr && head2 != nullptr) {
        if(head1->data <= head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }

        //move temp pointer to next nonde
        temp = temp->next;
    }

    // check in both lists if any element left to merged
    if(head1 != nullptr) temp->next = head1;
    else temp->next = head2;

    // return merged LL starting from the next of dummyNode
    return dummyNode->next;
}




// Function to print the LL
void printList(Node *head) {
    while(head != nullptr) {
        cout << head->data;
        if(head->next != nullptr) {
            cout << " ";
        }
        head = head->next;
    }
    cout << endl;
}


int main() {

    // First linked list: 5 -> 10 -> 15
    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    // Second linked list: 2 -> 3 -> 20
    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    Node* res = sortedMerge(head1, head2);
    cout << "The merged & sorted 2 linked lists is: ";
    printList(res);

    return 0;
}
