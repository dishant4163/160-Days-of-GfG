// Palindrome Sentence


// Link->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/string-palindromic-ignoring-spaces4723  



class Solution {
    public boolean sentencePalindrome(String s) {
        // code here

        // create a new string having only 
        // alphanumeric characters
        StringBuilder str = new StringBuilder();

        for(char ch : s.toCharArray()) {
            if(Character.isLetterOrDigit(ch) ) {
                str.append(Character.toLowerCase(ch) );
            }
        }

        // find reverse of this new string
        StringBuilder revStr = new StringBuilder(str.toString());
        revStr.reverse();

        // compare string and its reverse
        return str.toString().equals(revStr.toString());
    }
}
