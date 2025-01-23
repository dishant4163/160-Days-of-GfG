// Rotate a Linked List


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/rotate-a-linked-list



#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node *next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};




Node *rotate(Node *head, int k) {
    if(k == 0 || head == nullptr) return head;

    Node *temp = head;
    int len = 1;

    while(temp->next != nullptr) {
        temp = temp->next;
        len++;
    }

    k %= len;
    // if after modulo k gives zero then return head
    if(k == 0) return head;

    temp->next = head; // Make the linked list circular

    temp = head;
    for(int i = 1; i < k; i++) {
        temp = temp->next;
    }

    head = temp->next;

    temp->next = nullptr;

    return head;
}



void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}




int main() {

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = rotate(head, 6);
    printList(head);


    return 0;
}
