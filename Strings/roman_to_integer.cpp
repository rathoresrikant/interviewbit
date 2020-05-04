/*
Roman To Integer
Given a string A representing a roman numeral. Convert A into integer. A is guaranteed to be within the range from 1 to 3999. NOTE: Read more details about roman numerals at Roman Numeric System
Input Format
The only argument given is string A.
Output Format
Return an integer which is the integer verison of roman numeral string.
For Example
Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
*/
int Solution::romanToInt(string A) {
    int m = A.length(), res = 0;
    map <char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;
    res = roman[A[m-1]];
    for(int i=m-2; i>=0; i--)
    {
        if(roman[A[i]] >= roman[A[i+1]])
        res += roman[A[i]];
        else
        res = res - roman[A[i]];
    }
    return res;
}
