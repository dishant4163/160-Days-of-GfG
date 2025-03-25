// Stickler Thief


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/stickler-theif-1587115621   



#include<bits/stdc++.h>
using namespace std;


int findMaxSum(vector<int>& arr) {
    // code here
    int n = arr.size();

    int secondLast = 0, last = arr[0], ans = 0;

    for(int i = 1; i < n; i++) {
        ans = max(arr[i] + secondLast, last);

        secondLast = last;
        last = ans;
    }

    return ans;
}


int main() {

    vector<int> arr= {6,5,5,7,4};
    cout << "The output is: " << findMaxSum(arr); 


    return 0;
}
