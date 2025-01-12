// Count Possible Triangles


// Problem-Link-> 
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-possible-triangles-1587115620    



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int countTriangles(vector<int> &arr) {
    int count = 0;
    sort(arr.begin(), arr.end());

    for(int i = 2; i < arr.size(); i++) {
        int left = 0, right = i-1;

        while(left < right) {
            if(arr[left] + arr[right] > arr[i]) {
                count += right - left;
                right--;
            }
            else left++;
        }
    }

    return count;
}




int main() {

    vector<int> arr = {4, 6, 3, 7};
    cout << "Count of possible Triangles is: " << countTriangles(arr);

    return 0;
}
