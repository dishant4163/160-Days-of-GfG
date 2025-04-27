// Unique Number-ii



// Problem Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/finding-the-numbers0215       



#include<bits/stdc++.h>
using namespace std;




vector<int> singleNum(vector<int>& arr) {
    // Code here.
    int xorVal = 0;
    for(auto val : arr) {
        xorVal = val ^ xorVal;
    }

    int setBit = (xorVal & -xorVal);

    vector<int> ans(2, 0);
    for(int num : arr) {
        //if bit is not set, it belongs to the 1st set
        if((num & setBit) == 0) {
            ans[0] ^= num;
        } 

        //if bit is set, it belongs to the 2nd set
        else ans[1] ^= num;
    }

    if(ans[0] > ans[1]) {
        swap(ans[0], ans[1]);
    }

    return ans;
}





int main() {

    vector<int> arr = { 1, 2, 3, 2, 1, 4 };
    vector<int> ans = singleNum(arr);
    cout << "The output is " << "[" << ans[0] << ", " << ans[1] << "]" << endl;



    return 0;
}