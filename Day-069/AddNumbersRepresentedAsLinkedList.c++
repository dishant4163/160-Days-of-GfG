// Add Two Numbers Represented as Linked List


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/add-two-numbers-represented-by-linked-lists

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};



// Function to Reverse a LL
Node* reverseLL(Node* head) {
    Node *temp = head, *prev = nullptr, *front = nullptr;

    //loop to reverse the LL
    while(temp != nullptr) {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}


//Function to remove Leading Zeros in LL
Node *removeLeadingZeros(Node* head) {
    while(head->next != nullptr && head->data == 0) {
        head = head->next;
    }
    return head;
}


// Main Function to Add LL
Node* addTwoLists(Node* num1, Node* num2) {
    // code here
    num1 = reverseLL(num1);
    num2 = reverseLL(num2);

    int carry = 0;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(num1 != NULL || num2 != NULL || carry) {
        int sum = carry;
        if(num1) {
            sum += num1->data;
            num1 = num1->next;
        }

        if(num2) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
    }

    return removeLeadingZeros(reverseLL(dummyNode->next));
}





// Function to print LinkedList
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout <<" ";
}


int main() {

    // Creating first linked list: 1 -> 2 -> 3
    // (represents 123)
    Node *num1 = new Node(1);
    num1->next = new Node(2);
    num1->next->next = new Node(3);

    // Creating second linked list: 9 -> 9 -> 9
    // (represents 999)
    Node *num2 = new Node(9);
    num2->next = new Node(9);
    num2->next->next = new Node(9);

    Node *sum = addTwoLists(num1, num2);
    printList(sum);



    return 0;
}
