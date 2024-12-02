// String to Integer - Write your own atoi()
//Problem Link->
// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/implement-atoi   

/*  Cases for atoi() conversion:

 # Skip any leading whitespaces.
 # Check for a sign ('+' or '-'), default to positive if no sign is present.
 # Read the integer by ignoring leading zeros until a non-digit character is 
encountered or end of the string is reached. If no digits are present, return 0.
 # If the integer is greater than 2^31 - 1, then return 2^31 - 1 and if the 
integer is smaller than -2^31, then return -2^31.

*/


/* Algorithm:

The basic idea is to follow the atoi() algorithm in order and covering all the edge cases:

 # Skip the leading whitespaces by iterating from the first character.
 # Now, check for at most one sign character ('+' or '-') and maintain a sign 
variable to keep track of the sign of the number.
 # Finally, read all the digits and construct the number until the first non-digit 
character is encountered or end of the input string is reached.
 # While constructing the number, if the number becomes greater than 2^31 - 1, print 2^31 - 1. 
Similarly, if the number becomes less than -2^31, print -2^31.

*/


/*// How to check if the number is greater than 2^31 - 1 or smaller than -2^31 ?

The naive way is to use a data type which has size greater than 32 bits like long, 
BigInteger to store the number. However, we can also use 32-bit integer by appending the 
digits one-by-one and for each digit, check if appending current digit to the number will make it 
underflow (< -231) or overflow(> 231- 1). While appending a digit to the current number, we can have 3 cases:

  Case 1: current number < (2^31 - 1)/10 or current number > -2^31/10: Simply append the digit to the current 
number as it won't cause overflow/underflow.
  Case 2: current number > (2^31 - 1)/10 or current number < -2^31/10: Return (2^31 - 1) in case of overflow and -2^31 in case of underflow.
  Case 3: current number = (2^31 - 1)/10 or current number = -2^31/10: In this case, if current number = (2^31 - 1)/10, 
then only 0-7 digits can be appended and if current number = -2^31/10, then only 0-8 digits can be appended.

*/


// In the below implementation, we are constructing the absolute value of the number, 
// so we can simply compare with (2^31 - 1)/10 and avoid comparing with -2^31/10.


#include<bits/stdc++.h>
using namespace std;

int myAtoi(char* s) {
    int sign = 1, ans = 0, i = 0;

    //ignore leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    //store the sign of number
    if (s[i] == '-' || s[i] == '+') {
        if(s[i++] == '-')
        sign = -1;
    }

    while(s[i] >= '0' && s[i] <= '9') {
        //handle the Overflow / underflow test cases
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] - '0' > 7)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        // else append current digit to the ans
        ans = 10 * ans + (s[i++] - '0');
    }

    return ans * sign;
}


int main() {

    char s[] = "  -0012g4";
    cout << "Output is " << myAtoi(s);

    return 0;
}
