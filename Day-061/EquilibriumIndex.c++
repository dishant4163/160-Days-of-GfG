// Equilibrium Index


// Problem-Link->
//    


#include<bits/stdc++.h>
using namespace std;

int equilibriumPoint(vector<int>& arr) {
    int n = arr.size();
    int prefixSum = 0, totalSum = 0;

    for(int i=0; i < n; i++) { // calculate total array sum
        totalSum += arr[i];
    }

    //iterate pivot over all elements of the array till left array part != right array part
    for(int it = 0; it < n; it++) {
        int suffixSum = totalSum - prefixSum - arr[it];

        if(suffixSum == prefixSum) {
            return it;
        }

        prefixSum += arr[it];
    }

    return -1; // no equilibrium point
}



int main() {

    vector<int> arr = { 1, 7, 3, 6, 5, 6 };
    cout << "The equilibrium index is: " << equilibriumPoint(arr) << endl;


    return 0;
}
