// Implement Pow | Write a function to calulate pow(b, e)


// Problem-Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/powx-n


#include<bits/stdc++.h>
using namespace std;

//Solving Recursively
double power(double b, int e) {
    // Base case
    if(e == 0) return 1.0;

    double half = power(b, e/2);
    if(e % 2 == 0) return half * half;
    else {
        return (e > 0) ? b*half*half : (half*half) / b;
    }
}



int main() {

    double b = 3.0;
    int e = 5;
    double res = power(b, e);
    cout << "The output is : " << res;



    return 0;
}

