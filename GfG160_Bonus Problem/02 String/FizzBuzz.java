// Fizz Buzz



// Problem-Link->    https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/fizz-buzz 



// Approach 1 By String Concatenation

import java.util.ArrayList;

class Solution {
    public static ArrayList<String> fizzBuzz(int n) {
        // code here
        ArrayList<String> ans = new ArrayList<>();

        for(int i = 1; i <= n; i++) {
            String str = "";

            // if divisble by 3, then add fizz
            if(i % 3 == 0) str += "Fizz";

            // if divisble by 5, then add Buzz
            if(i % 5 == 0) str += "Buzz";

            //add number if not divisible by 3 or 5
            if(str.isEmpty()) str += i;

            ans.add(str); // append current answer to list
        }

        return ans;
    }
}







// Approach 2 using map

import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public static ArrayList<String> fizzBuzz(int n) {
        // code here
        ArrayList<String> ans = new ArrayList<>();

        //hashmap to store all FizzBuzz
        HashMap<Integer, String> mp = new HashMap<>();
        mp.put(3, "Fizz");
        mp.put(5, "Buzz");

        //list of divisors array on which we iterate 
        int [] div = {3, 5};

        for(int i = 1; i <= n; i++) {
            StringBuilder str = new StringBuilder();

            for(int d : div) {
                // if i is divissble by d then add the corresponding
                // string mapped to d
                if(i % d == 0) {
                    str.append(mp.get(d));
                }
            }

            // if not divisble by 3 or 5
            if(str.length() == 0) str.append(i);

            //add the current answer to ans list
            ans.add(str.toString());
        }

        return ans;
    }
}





// Key Difference

//  Arrays use .length (no parentheses) to get the size of the array.
//  Strings use .length() (with parentheses) because it's a method.
//  String: Immutable (unchangeable). Every time you modify it, a new String object is created.

//  StringBuilder: Mutable (changeable). It's more efficient when you need to modify or append strings repeatedly.
