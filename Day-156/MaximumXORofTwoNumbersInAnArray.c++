// Maximum XOR of Two Numbers in an Array



// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tries-gfg-160/problem/maximum-xor-of-two-numbers-in-an-array   



#include<bits/stdc++.h>
using namespace std;



struct TrieNode {
    TrieNode* links[2];

    TrieNode() {
        links[0] = links[1] = NULL;
    }

    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    void put(int bit, TrieNode* node) {
        links[bit] = node;
    }

    TrieNode* get(int bit) {
        return links[bit];
    }
};

class Trie {
  private:
    TrieNode *root;

    public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode *node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // get SetBit
            if(!node->containsKey(bit)) {
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        TrieNode *node = root;
        int maxNum = 0;

        for(int i= 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // get Nums Setbit
            if(node->containsKey(!bit)) {
                maxNum = (maxNum | (1 << i));
                node = node->get(1-bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        Trie *trie = new Trie();

        trie->insert(arr[0]);

        int maxi = 0;
        for(int i = 1; i < arr.size(); i++) {
            maxi = max(trie->getMax(arr[i]), maxi);
            trie->insert(arr[i]);
        }

        return maxi;
    }
};



int main() {
    Solution obj;

    vector<int> arr = {26, 100, 25, 13, 4, 14};
    cout << "The output is " << obj.maxXor(arr) << endl;


    return 0;
}
