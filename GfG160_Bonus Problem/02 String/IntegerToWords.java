// Integer To Words 



// Problem-Link->   https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/number-to-words0335     



// Approach-1 By breaking down the number into groups of three digits
// Time Complexity: O(log10(n)) - As we are dividing the number by a multiple of ten (like 1000, 100, 10), reducing the number logarithmically.
// Auxiliary Space: O(1)

class Solution {
    String convertToWords(int n) {
        // code here
        if(n == 0) return "Zero";

        // words for numbers 0 to 19
        String[] units = {"", "One", "Two", "Three",
            "Four",    "Five",      "Six",      "Seven",
            "Eight",   "Nine",      "Ten",      "Eleven",
            "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };

        // Words for numbers multilple of 10
        String[] tens = {
            "",     "",     "Twenty",  "Thirty", "Forty",
            "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" 
        };

        String[] multiplier = {"", "Thousand", "Million", "Billion"};

        String ans = "";
        int group = 0;

        //process number in group of 1000s
        while(n > 0) {
            if(n % 1000 != 0) {
                int val = n % 1000;
                String temp = "";

                //handle 3 digit number
                if(val >= 100) {
                    temp = units[val / 100] + " Hundred ";
                    val %= 100;
                }

                //handle  2 digit number
                if (val >= 20) {
                    temp += tens[val/10] + " ";
                    val %= 10;
                }

                //handle unit number
                if(val > 0) {
                    temp += units[val] + " ";
                }

                // Add the multiplier according to the group
                temp += multiplier[group] + " ";

                ans = temp + ans; // Prepend instead of append to maintain correct order
            }

            n /= 1000;
            group++;
        }

        // Remove trailing space
        return ans.trim();
    }
}







// Approach-2 Recursion (By Mapping Key Numeric Values with English Words)

class Solution {

    static String helpConvertToWords(int n, int[] Values, String[] words) {
        String ans = "";

        for(int i = 0; i < val.length; i++) {
            int value = Values[i];
            String word = words[i];

            // If the number is greater than or equal to current numeric value
            if (n >= value) {

                // Append the quotient part, If the number is greater
                // than or equal to 100 then only we need to handle that
                if(n >= 100) 
                    ans += helpConvertToWords(n/value, Values, words) + " ";


                // Append the word for numeric value
                ans += word;

                // Append the remainder part
                if(n % value > 0)
                    ans += " " + helpConvertToWords(n % value, Values, words);

                return ans;
            }
        }

        return ans;
    }

    static String convertToWords(int n) {
        // code here
        if(n == 0) return "Zero";

        int[] val = {1000000000, 1000000, 1000, 100, 90, 80, 70, 60, 50,
                40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8,
                7, 6, 5, 4, 3, 2, 1
        };

        String[] words = {
            "Billion", "Million", "Thousand", "Hundred",
            "Ninety", "Eighty", "Seventy", "Sixty", "Fifty",
            "Forty", "Thirty", "Twenty", "Nineteen",
            "Eighteen", "Seventeen", "Sixteen", "Fifteen",
            "Fourteen", "Thirteen", "Twelve", "Eleven",
            "Ten", "Nine", "Eight", "Seven", "Six", "Five",
            "Four", "Three", "Two", "One"
        };

        return helpConvertToWords(n, val, words);
    }
}
