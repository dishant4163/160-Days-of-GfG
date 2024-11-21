// Reverse An Array


// Day-3 Problem Link =>
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/reverse-an-array


#include<bits/stdc++.h>
using namespace std;


void reverseArray(vector<int> &arr) {
    // code here

    int Lptr = 0, Rptr = arr.size() - 1;

    while(Lptr < Rptr) {
        swap(arr[Lptr], arr[Rptr]);
        Lptr++; Rptr--;
    }

}


int main() {

    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";        
    }



    return 0;
}
