// Implement Trie Data Structure


// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tries-gfg-160/problem/trie-insert-and-search0651    



#include<bits/stdc++.h>
using namespace std;



// Node structure for Trie
class TrieNode { // we can also use struct, bcz by default it is public
    private:

    TrieNode *links[26];   // array to store links to child nodes each index represents a letter
    bool flag = false; //Flag indicates if the node marks the end of a word

    public:
    // Check if the node contains a specific key (letter)
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); // is not NULL means this ch exists in trie
    }

    // Insert a new node with a specific key (letter) into the Trie
    void put(char ch, TrieNode *newNode) {
        // for this character the reference Node is this newNode
        links[ch - 'a'] = newNode;
    }

    // Get the node with a specific key (letter) from the Trie
    TrieNode *get(char ch) {
        return links[ch - 'a'];
    }

    // Set the current node as the end of a word
    void setEnd() {
        flag = true;
    }

    // Check if the current node marks the end of a word
    bool isEnd() {
        return flag;
    }
};



class Trie {
    private:
    TrieNode *root;

    public:

    Trie() {
        // implement Trie
        root = new TrieNode();
    }

    void insert(string& word) {
        // insert word into Trie
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                // Create a new node for the letter if not present
                node->put(word[i], new TrieNode()); // new Node() means to new trie while inserting
            }
              // Move to the reference trie next no
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }


    bool search(string& word) {
        // search word in the Trie
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            // if this not contains word[i]
            if(!node->containsKey(word[i])) {
                // If a letter is not found, the word is not in the Trie
                return false;
            }
            // Move to the next node
            node = node->get(word[i]); ////i.e, it constains word[i]
        }
        // Check if the last node marks the end of a word
        return node->isEnd();
    }


    bool isPrefix(string& word) {
        // search prefix word in the Trie
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {  
                // If a letter is not found, there is
                // no word with the given prefix
                return false;
            }
            // Move to the next node
            node = node->get(word[i]); ////i.e, letter found there is word with the given prefix
        }
        // The prefix is found in the Trie
        return true;
    }
};




int main() {

    Trie trie; // Create an instance of the Trie

    // Insert words into the Trie
    vector<string> arr = {"and", "ant", "do", "dad"};
    for (string& s : arr) {
        trie.insert(s); // Insert each word into the Trie
    }

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string& s : searchKeys) {
        if (trie.search(s))
            cout << "true ";
        else
            cout << "false ";
    }
    cout << "\n";

    // One by one search for prefixes
    vector<string> prefixKeys = {"ge", "ba", "do", "de"};
    for (string& s : prefixKeys) {
        if (trie.isPrefix(s))
            cout << "true ";
        else
            cout << "false ";
    }
    cout << "\n";



    return 0;
}
