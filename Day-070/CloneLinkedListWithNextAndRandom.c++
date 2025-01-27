// Clone linked list with next and random pointers


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/clone-a-linked-list-with-next-and-random-pointer



#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *next, *random;
    Node(int x) {
        data = x;
        next = random = NULL;
    }
};



// Step-1 Insert CopyNodes in Between
void insertCopyNodesINBetween(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        Node* copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
}


// Step-2 Connect Random Pointers
void connectRandomPtr(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        // access copied node
        Node* copyNode = temp->next;
        //if original node has random ptr
        if(temp->random) {
            // Point the copied node's random to the
            // corresponding copied random node
            copyNode->random = temp->random->next;
        }
        else {
            // Set the copied node's random to
            // null if the original random is null
            copyNode->random = NULL;
        }
        // move to next ORiginal node
        temp = temp->next->next;
    }
}


// Step-3 Function to retrieve the deep copy of the linked list
// Or Connect next pointer
Node* getDeepCopyList(Node* head) {
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while(temp != NULL) {
        res->next = temp->next;
        res = res->next;

        // Disconnect and revert back to the
        // initial state of the original linked list
        temp->next = temp->next->next;
        //move to next node
        temp = temp->next;
    }

    return dummyNode->next;
}



// Main function to Clone LL
Node* cloneLinkedList(Node* head) {
    if(head != nullptr) return head;

    // Step-1
    insertCopyNodesINBetween(head);
    // Step-2
    connectRandomPtr(head);
    // Step-3
    Node* cloneLL = getDeepCopyList(head);

    return cloneLL;
}






// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << "(";
            if(head->random)
                cout << head->random->data << ")";
            else 
                cout << "null" << ")";
            if(head->next != NULL)
                cout << " -> ";
        head = head->next;
    }
    cout << endl;
}





int main() {

    // Creating a linked list with random pointer
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    // Print the original list
    cout << "Original linked list: ";
    printList(head);

    // Function call
    Node* clonedList = cloneLinkedList(head);
cout << endl;
    cout << "Cloned linked list: ";
    printList(clonedList);


    return 0;
}
