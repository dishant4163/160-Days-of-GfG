// Minimum Repeat To Make Substring


// Problem-Link->    https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645




// Brute force (Matching Characters of s2 with repeated occurrence of s1)
// TC- O(n*m) SC- O(1)
class Solution {
    static int minRepeats(String s1, String s2) {
        // code here
        int n = s1.length(), m = s2.length();

        for(int i = 0; i < n; i++){
            int repeat = 1, indx1 = i;
            boolean found = true;

            //compare each character of s2 with s1
            for(int indx2 = 0; indx2 < m; indx2++) {
                if(s1.charAt(indx1) != s2.charAt(indx2)) {
                    found = false;
                    break;
                }
                indx1++;

                // reached the end of s1, then reset the index to 0
                if(indx1 == n){
                    indx1 = 0;

                    // for some remaining character in s2 then s1 needs to
                    // repeat again so increase the repetitions by 1
                    if(indx2 != m-1) repeat++;
                }
            }

            if(found) return repeat;
        }

        return -1;
    }
}






// OPtimal Soln (Using KMP Algo)
// TC- O(n + m),  SC - O(m)

class Solution {

    // function to compute the LPS Array
    static void getLPSArr(String s, int[] lps) {
        int n = s.length(), len = 0, ind = 1;

        lps[0] = 0; // lps[0] is always 0

        // loop calculates lps[i] for i=1 to s.length() - 1 
        while(ind < n) {
            if (s.charAt(ind) == s.charAt(len)) {
                len++;
                lps[ind] = len;
                ind++;
            } 
            else {
                // If len is 0, then we have no common prefix which is also a suffix
                if(len == 0) {
                    lps[ind] = 0;
                    ind++;
                } else {
                    len = lps[len - 1]; // Note that we do not move to the next index
                }
            }
        }
    }



    // function to find the occurrence of pat in txt
    static boolean KMPSearch(String txt, String pat, int[] lps, int rep) {
        int n = txt.length(), m = pat.length();
        int i = 0, j = 0;

        while(i < n * rep) {
            if(txt.charAt(i % n) == pat.charAt(j)) {
                i++;
                j++;

                if(j == m) return true;
            }
            else {
                if(j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }



    // function to find Minimum number of times s1 has to be
    // repeated such that s2 is a substring of it
    static int minRepeats(String s1, String s2) {
        // code here
        int n = s1.length(), m = s2.length();

        //declare & compare lps 
        int[] lps = new int[m];
        getLPSArr(s2, lps);

        // find minimum number of times s1 needs to be repeated
        // to get as long as S2
        int x = (m + n - 1) / n;

        //check when string S1 is repeated x times
        if(KMPSearch(s1, s2, lps, x)) return x;

        // check when string S1 is repeated (x+1) times
        if(KMPSearch(s1, s2, lps, x + 1)) return x + 1;

        // If string s2 was not found, return -1
        return -1;
    }
}
