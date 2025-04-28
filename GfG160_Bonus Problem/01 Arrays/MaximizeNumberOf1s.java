// Maximize Number of 1's



// Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/maximize-number-of-1s0905




class Solution {
    // k is the maximum number of zeros allowed to flip
    public int maxOnes(int arr[], int k) {
        // code here
        int n = arr.length;
        int maxLen = 0, cntZero = 0;
        
        int left = 0;
        
        for(int right = 0; right < n; right++) {
            // If encounter a 0, increment the zero count
            if(arr[right] == 0) cntZero++;

            // If zero count exceeds k, shrink the window from the left
            while(cntZero > k) {
                if(arr[left] == 0) {
                    cntZero--;
                }
                left++;
            }

            // Calculate the size of the current valid window
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
}
