/*
Integer To Roman
Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version
 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using "See Expected Output" For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations.

Input Format
The only argument given is integer A.
Output Format
Return a string denoting roman numeral version of A.
Constraints
1 <= A <= 3999
For Example
Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"
*/
string Solution::intToRoman(int A) {
    string res;
    int roman[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000}, i = 12;
    string str[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    while(A > 0)
    {
        int div = A/roman[i];
        A = A%roman[i];
        while(div--)
        {
            res.append(str[i]);
        }
        i--;
    }
    return res;
}
