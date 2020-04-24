/*
Ways to Decode
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.
Input Format:
The first and the only argument is a string A.
Output Format:
Return an integer, representing the number of ways to decode the string.
Constraints:
1 <= length(A) <= 1e5
Example :
Input 1:
    A = "8"

Output 1:
    1

Explanation 1:
    Given encoded message "8", it could be decoded as only "H" (8).

    The number of ways decoding "8" is 1.

Input 2:
    A = "12"

Output 2:
    2

Explanation 2:
    Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).

    The number of ways decoding "12" is 2.
*/

int Solution::numDecodings(string A)
{
    int m = A.length();
    vector <int> dp(m+2, 0);
    dp[m] = 1;
    for(int i=m-1; i>=0; i--)
    {
        if(A[i] == '0')
            dp[i] = 0;
        else
        if(A[i] == '1')
        {
            dp[i] = dp[i+1] + dp[i+2];
        }
        else
        if(A[i] == '2' && A[i+1] <= '6')
        {
            dp[i] = dp[i+1] + dp[i+2];
        }
        else
        {
            dp[i] = dp[i+1];
        }
    }
    return dp[0];
}
