// Sort an array of 0s, 1s and 2s - Dutch National Flag Problem  


// Problem-Link->
//   

#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr) {
    int n = arr.size();
    int mid = 0, low = 0, high = n-1;

    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        } else if (arr[mid] == 1) {
            mid ++;
        } else {
            swap(arr[mid], arr[high--]);
        }
    }
}


int main() {

    vector<int> arr = { 0, 1, 2, 0, 1, 2 };
    int n = arr.size();

    sort012(arr);

    cout << "Sorted Array is: " ;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
