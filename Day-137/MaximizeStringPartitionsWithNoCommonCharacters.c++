// Maximize String Partitions with No Common Characters


// Problem-Link->     


#include<bits/stdc++.h>
using namespace std;


int maxPartitions(string &s) {
    // code here
    int n = s.size(), cntPartition = 0;

    vector<int> lastSeen(26, -1);

    for(int i = n-1; i >= 0; i--) {
        if(lastSeen[s[i] - 'a'] == -1) {
            lastSeen[s[i] - 'a'] = i;
        }
    }

    int trackLastSeen = -1;

    for(int i=0; i < n; i++) {
        trackLastSeen = max(lastSeen[s[i]-'a'], trackLastSeen);

        if(trackLastSeen == i) cntPartition++;
    }

    return cntPartition;
}


int main() {

    string s = "acbbcc";
    cout << "The output is " << maxPartitions(s) << endl;


    return 0;
}
