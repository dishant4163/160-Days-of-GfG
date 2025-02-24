// Find Median from Running Data Stream


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/find-median-in-a-stream-1587115620



#include<bits/stdc++.h>
using namespace std;


vector<double> getMedian(vector<int> &arr) {
    // code here
    int n = arr.size();
    vector<double> ans; 

    // Max-Heap for storing smaller half elements i.e,
    // elements in left part of Array(ele > MedianEle)
    priority_queue<int> leftMaxheap;

    // Min-Heap for storing greater half elements i.e,
    // elements in right part of Array(ele < MedianEle)
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

    for(int i = 0; i < n; i++) {
        leftMaxheap.push(arr[i]); // insert new ele into max heap

        // move the top of max heap to min heap to maintain order
        int temp = leftMaxheap.top();
        leftMaxheap.pop();
        rightMinHeap.push(temp);

        // balance heaps if minheap has more elements
        if(rightMinHeap.size() > leftMaxheap.size()) {
            temp = rightMinHeap.top();
            rightMinHeap.pop();
            leftMaxheap.push(temp);
        }

        // compute median based on heap sizes
        double median;
        if(leftMaxheap.size() != rightMinHeap.size()) median = leftMaxheap.top();
        else median = (double)(leftMaxheap.top() + rightMinHeap.top()) / 2;

        ans.push_back(median);
    }

    return ans;
}

int main() {

    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> res = getMedian(arr);
    cout << fixed << setprecision(2);

    cout << "The output is: ";
    for (double median: res) 
        cout << median << " ";



    return 0;
}
