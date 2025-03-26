// Stickler Thief-ii


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/house-robber-ii  


#include<bits/stdc++.h>
using namespace std;



// sticker thief-1
int findMaxSum(vector<int>& arr) {
    int n = arr.size(), prev2 = 0, prev = arr[0];

    for(int i = 1; i < n; i++) {
        int pick = arr[i];
        
        if(i > 1) pick += prev2;
        int notPick = 0 + prev;
        int cur = max(pick, notPick);
        
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int maxValue(vector<int>& arr) {
    // your code here
    int n = arr.size();

    //base case
    if(n == 0) return 0;
    if(n == 1) return arr[0];

    vector<int> temp1, temp2;
    for(int i = 0; i < n; i++) {
        if(i != 0) temp1.push_back(arr[i]); // leave 1st array element
        if(i != n-1) temp2.push_back(arr[i]); // leave last array element
    }

    return max(findMaxSum(temp1), findMaxSum(temp2));
}



int main() {

    vector<int> arr = {2, 2, 3, 1, 2};
    cout << "The output is: " << maxValue(arr);


    return 0;
}
