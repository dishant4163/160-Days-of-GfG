// Container with Most Water



// Problem-Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/container-with-most-water0535   




#include<bits/stdc++.h>
using namespace std;

int maxWater(vector<int> &arr) {
    int l = 0, r = arr.size() - 1, ans = 0;

    while(l < r) {
        int waterAmt = min(arr[l], arr[r]) * (r - l);
        ans = max(ans, waterAmt);

        if(arr[l] < arr[r])
            l++;
        else
            r--;
    }

    return ans;
}


int main() {

    vector<int> arr = {2, 1, 8, 6, 4, 6, 5, 5};
    cout << "The maximum amount of water container can have is: " ;
    cout << maxWater(arr);


    return 0;
}
