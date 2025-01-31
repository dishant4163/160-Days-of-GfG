// LRU Cache (using DLL & HashMap)


// Problem Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/lru-cache 


#include<bits/stdc++.h>
using namespace std;


class LRUCache {

public:
    // Declare Node for DLL
    class Node {
        public:
        int key, value;
        Node* next;
        Node* prev;

        Node (int KEY, int VALUE) {
            key = KEY;
            value = VALUE;
            next = nullptr;
            prev = nullptr;
    }
};


private:
    unordered_map<int, Node*> mp;
    int capacity;
    Node *head = new Node(-1, -1); // dummy Head
    Node *tail = new Node(-1, -1); // dummy Tail

    // Function to add a node After the head
    // in DLL(mark it as most recently used)
    void addNodeAfterHead(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    //function to remove a node from DLL
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }


public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // if present in map
        if(mp.find(key) != mp.end()) {
            Node* referNode = mp[key];
            deleteNode(referNode);
            addNodeAfterHead(referNode);
            return referNode->value;
        }

        return -1; // else return -1 if map doesn't have key
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        //if Key exist, update the value & move the node to the front
        if(mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            existingNode->value = value;
            deleteNode(existingNode);
            addNodeAfterHead(existingNode);
            return;
        }
        else { //key does not exist or cache is Full already
            if(mp.size() == capacity) {
                Node *node = tail->prev;
                //Cache is full, remove the LRU items i.e, tail->prev->key
                mp.erase(node->key);
                deleteNode(node);
            }

            //create a new Node, insert it into the Cache 
            Node *node = new Node(key, value);
            mp[key] = node;
            addNodeAfterHead(node);
        }
    }


};





int main() {

    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;


    return 0;
}
