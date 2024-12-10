// H-Index

// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/find-h-index--165609  


#include<bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> freq(n + 1);

    for(int i = 0; i < n; i++) {
        if(citations[i] >= n) {
            freq[n] += 1;
        } else {
            freq[citations[i]] += 1;
        }
    }

    int index = n, it = freq[n];

    while(it < index) {
        index--;
        it += freq[index];
    }

    return index;
}


int main() {

    vector<int> citations = {6, 0, 3, 5, 3};
    cout << "The output is: " << hIndex(citations) << "\n";


    return 0;
}
