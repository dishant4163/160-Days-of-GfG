// Day-1 -> Arrays -> Second Largest_GfG

// GfG Problem Link ->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/second-largest3735


#include<bits/stdc++.h>
using namespace std;

int getSecondLargest(vector<int> &arr) {
    int largest = arr[0], secondLargest = INT_MIN;

    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}



int main() {

    vector<int> arr = {12, 35, 1, 10, 34, 1};
    int secondLargest = getSecondLargest(arr);
    cout << "The second largest element is: " << secondLargest << endl;


    return 0;
}

