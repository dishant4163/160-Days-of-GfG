// Count distinct elements in every window of size K


// Problem-Link->
// 


#include<bits/stdc++.h>
using namespace std;



vector<int> countDistinct(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> count;
    unordered_map<int, int> freqMpp;

    //store frequency of elements of 1st Window
    for(int i=0; i < k; i++) {
        freqMpp[arr[i]] += 1;
    }

    // store the count of distinct elements of 1st window
    count.push_back(freqMpp.size());

    for(int i = k; i < n; i++) {
        freqMpp[arr[i]] += 1;
        freqMpp[arr[i - k]] -= 1;

        // if the freq of arr[i-k] becomes 0
        // remove it from map
        if(freqMpp[arr[i - k]] == 0) freqMpp.erase(arr[i-k]);

        count.push_back(freqMpp.size());
    }

    return count;
}



int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    vector<int> res = countDistinct(arr, k);
    cout << "Number of distinct elements in every window of size = " << k <<" is: " ;
    for(int ele: res)
        cout << ele << " ";
    return 0;
}
