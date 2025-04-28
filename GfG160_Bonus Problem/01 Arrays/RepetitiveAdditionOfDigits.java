// Repetitive Addition Of Digits


// link->    https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/repetitive-addition-of-digits2221




//Mathematical Insight (Digital Root Formula)
class Solution {
    public int singleDigit(int n) {
        // If n is 0, return 0 (though this is not strictly needed based on constraints)
        if (n == 0) {
            return 0;
        }
        
        // Using the digital root formula
        return 1 + (n - 1) % 9;
    }
}
