// Detect Loop or Cycle in Linked List



// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/detect-loop-in-linked-list



#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};



bool detectLoop(Node* head) {
    Node *slow = head, *fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return true;
        }
    }

    return false;
}





int main() {

    // Create a linked list: 1 -> 3-> 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    // Create a loop
    head->next->next->next = head->next;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";


    return 0;
}
