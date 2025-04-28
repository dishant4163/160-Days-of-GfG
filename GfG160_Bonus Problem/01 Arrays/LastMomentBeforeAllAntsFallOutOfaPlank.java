// Last Moment Before All Ants Fall Out Of a Plank 


// Link->    https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/last-moment-before-all-ants-fall-out-of-a-plank




class Solution {
    public int getLastMoment(int n, int left[], int right[]) {
        // code here
        int maxLeft = 0, maxRight = 0;

        for(int movement : left) {
            maxLeft = Math.max(maxLeft, movement);
        }

        for(int movement : right) {
            maxRight = Math.max(maxRight, n - movement);
        }

        return Math.max(maxLeft, maxRight);
    }
}
