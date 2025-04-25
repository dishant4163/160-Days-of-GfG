// Find Missing Number in an Array



// Problem-Link->    https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/missing-number-in-array1416   



#include<bits/stdc++.h>
using namespace std;



int missingNum(vector<int>& arr) {
    // code here
    int n = arr.size() + 1;
    int xor1 = 0, xor2 = 0;

    for(int i = 0; i < n-1; i++) {
        xor1 ^= arr[i];
    }

    for(int i = 1; i <= n; i++) {
        xor2 ^= i;
    }

    return xor1 ^ xor2;
}



int main() {

    vector<int> arr = {8, 2, 4, 5, 3, 7, 1}; 
    cout << "The missing number is " << missingNum(arr) << endl;  


    return 0;
}
