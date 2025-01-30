// Detect and Remove Loop in Linked List



// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/remove-loop-in-linked-list 


#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};



// Function to remove a loop in the linked list.
void removeLoop(Node* head) {
    // code here
    if(head == NULL || head->next == NULL) return;
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) break;
    }

    if(slow != fast) return;
    slow = head;

    if(slow == fast) {
        while(fast->next != slow) {
            fast = fast->next;
        }
    }
    else {
        while(slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = nullptr;
}



void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}



int main() {

    // Create a hard-coded linked list:
    // 1 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
    // Create a loop
    head->next->next->next = head->next;

    removeLoop(head);
    printList(head);

    return 0;
}
