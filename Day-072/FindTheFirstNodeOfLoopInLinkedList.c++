// Find First Node of Loop in Linked List


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/find-the-first-node-of-loop-in-linked-list--170645  



#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};




Node* findFirstNode(Node* head) {
    Node *slow = head, *fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // if loop detected
        if(slow == head) {
            slow = head; // move slow to head

            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return nullptr;
}



int main() {

    // Create a linked list: 10 -> 15 -> 4 -> 20
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);

    head->next->next->next->next = head;

    Node* loopNode = findFirstNode(head);

    if (loopNode)
        cout << "The first node in the loop is: " << loopNode->data;
    else
        cout << "No loop present in Linked list " << -1;

    return 0;
}
