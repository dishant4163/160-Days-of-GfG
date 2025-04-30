// Longest Prefix Suffix


// Problem-Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/longest-prefix-suffix2527     



// Naive approach By Comparing each Proper Prefix with Suffix - O(n^2) Time and O(1) Space
class Solution {
    int longestPrefixSuffix(String s) {
        // code here
        int n = s.length(), ans = 0;

        for(int len = 1; len < n; len++) {
            int ind = n - len; // starting index of suffix

            boolean mark = true;
            // Comparing proper prefix with suffix of length 'len'
            for(int i = 0; i < len; i++) {
                if(s.charAt(i) != s.charAt(i + ind)) {
                    mark = false;
                    break;
                }
            }

            // if match then update the answer
            if(mark) ans = len;
        }

        return ans;
    }
}





// OPtimal Soln - Using LPS of KMP Algorithm - O(n) Time and O(n) Space

class Solution {
    int longestPrefixSuffix(String s) {
        // code here
        int n = s.length();
        int lps[] = new int[n];
        lps[0] = 0;

        // len stores the length of longest prefix which
        // is also a suffix for the previous index
        int len = 0;

        int ind = 1;
        while(ind < n) {
            if(s.charAt(ind) == s.charAt(len)) {
                // If characters match, increment the length of the longest prefix-suffix
                len++;
                lps[ind] = len;
                ind++;
            } 

            // If there is a mismatch
            else {
                if(len != 0) {
                    // Update len to the previous lps value
                    // to avoid redundant comparisons
                    len = lps[len - 1];
                }
                else {
                    // If no matching prefix found, set lps[i] to 0
                    lps[ind] = 0;
                    ind++;
                }
            }
        }

        // Last element of lps array will store the length of
        // longest prefix that is also suffix of entire string
        return lps[n - 1];
    }
}
