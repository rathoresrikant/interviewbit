/*
String count
Given an integer A, Find and return (total number of binary strings of length A, without having consecutive 1's) % 10^9 + 7.
Input Format
The only argument given is integer A.
Output Format
Return  (total number of binary strings of length A, without having consecutive 1's) % 10^9 + 7.
Constraints
1 <= A <= 10^5
For Example
Input 1:
    A = 2
Output 1:
    3
Explaination 1:
    "00"
    "01"
    "10"

Input 2:
    A = 3
Output 2:
    5
Explaination 2:
    "000"
    "001"
    "010"
    "100"
    "101"
*/

int Solution::solve(int A) {
    long long MOD = 1e9 + 7;
    long long a, b, c;
    a = 2;
    b = 3;
    if( A == 1)
        return a;
    if(A == 2)
        return b;
    for(int i=3; i<=A; i++)
    {
        c = (a%MOD + b%MOD)%MOD;
        a = b;
        b = c;
    }
    return b;
}
