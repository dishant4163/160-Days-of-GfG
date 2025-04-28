// Split Array In Three Equal Sum SubArrays


// Link-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/split-array-in-three-equal-sum-subarrays



class Solution {

    public List<Integer> findSplit(int[] arr) {
        // Return an array of possible answer, driver code will judge and return true or
        // false based on
        int n = arr.length;
        long sum = 0;
        
        for(int i = 0; i < n; i++) sum += arr[i];
        
        if(sum % 3 != 0) return Arrays.asList(-1, -1);
        
        long partitionSum = sum / 3, curSum = 0;
        boolean foundFirst = false;
        int i = -1, j = -1;
        
        for(int ind = 0; ind < n; ind++) {
            curSum += arr[ind];
            
            if(curSum == partitionSum && !foundFirst) {
                i = ind;
                foundFirst = true;
                curSum = 0; // reset to find next part
            } else if (curSum == partitionSum && foundFirst) {
                j = ind;
                return Arrays.asList(i, j);
            }
        }
        
        return Arrays.asList(-1, -1);
    }
}
