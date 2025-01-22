// Reverse a Linked List (Iterative)

// Tutorial Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/article/ODYw



// Problem Link-> 
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/reverse-a-linked-list




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



Node* reverseList(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    // using the 3-pointer approach
    Node *temp = head, *prev = NULL, *front;

    while(temp != NULL) {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}



// Function to print LL
void printList(Node* node) {
    while(node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}



int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked List:";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List:";
    printList(head);

    return 0;
}
