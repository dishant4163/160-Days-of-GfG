// CamelCase Pattern Matching


// Problem-link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/camelcase-pattern-matching2259 





import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> camelCase(String[] arr, String pat) {
        // code here

        List<String> ans = new ArrayList<>();

        for(String word : arr) {
            int i = 0, j = 0;

            while(i < word.length() && j < pat.length()) {
                if ( Character.isLowerCase(word.charAt(i))) {
                    i++;
                }

                else if (word.charAt(i) != pat.charAt(j)) break;

                else {
                    i++;
                    j++;
                }
            }

            if (j == pat.length()) ans.add(word);
        }

        return ans;
    }
}
