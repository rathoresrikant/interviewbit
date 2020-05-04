/*
Divisibility by 8
Given a number A in the form of string. Check if the number is divisible by 8 or not. Return 1 if it is divisible by 8 else return 0.
Input Format
The only argument given is string A.
Output Format Return 1 if it is divisible by 8 else return 0. Constraints
1 <= length of the String <= 100000
'0' <= A[i] <= '9'
For Example
Input 1:
    A = "16"
Output 1:
    1

Input 2:
    A = "123"
Output 2:
    0
*/
int Solution::solve(string A) {
    int m = A.length(), unit, tens, hundreds, num;
    unit = (int)(A[m-1] - '0');
    tens = (int)(A[m-2] - '0');
    hundreds = (int)(A[m-3] - '0');
    num = 100*hundreds + 10*tens + unit;
    if(num%8 == 0)
        return 1;
    return 0;
}
