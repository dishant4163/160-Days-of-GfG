//  Linked List Group Reverse/Reverse a Linked List in groups of given size 


// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/reverse-a-linked-list-in-groups-of-given-size


// References / Tutorial: ->  https://www.geeksforgeeks.org/reverse-a-linked-list-in-groups-of-given-size/ 




#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }

};



// Main Function to Reverse LL in K Groups
Node *reverseKGroup(Node *head, int k) {
    if(head == nullptr) return head;

    Node *temp = head;
    Node *newHead = NULL, *tail = NULL;

    while(temp != NULL) {
        Node *groupHead = temp;
        Node *prev = NULL;
        Node *nextNode = NULL;

        int cntK = 0;

        //reverse the nodes in current group
        while(temp != NULL && cntK < k) {
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
            cntK++;
        }

        if(newHead == NULL) newHead = prev;

        if(tail != NULL) tail->next = prev;

        tail = groupHead;
    }

    return newHead;
}






// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    // Creating a sample singly linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "The original Linked List is: ";
    printList(head);

    Node *ans = reverseKGroup(head, 3);
    cout << "Linked List Group Reverse is: ";
    printList(ans);





    return 0;
}

