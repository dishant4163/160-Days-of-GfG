// Rotate an Array the left (counter-clockwise direction) by d steps


#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArrayD(vector<int>arr, int k) {
    //solving in TC- O(logn)
    int n = arr.size();
    k = k%n;
    
    vector<int> solve;
    for (int i=k; i<n; i++) {
        solve.push_back(arr[i]);
    }
    for (int i=0; i<k; i++) {
        solve.push_back(arr[i]);
    }
    
    return solve;
}


// Function to rotate an array by d elements in counter-clockwise direction.
void rotateArr(vector<int>& arr, int d) {
    // code here

    arr = rotateArrayD(arr, d);
}



int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    
    rotateArr(arr, d);
    
    // Printing the rotated array
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;



    return 0;
}

