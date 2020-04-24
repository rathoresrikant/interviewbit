/*
Longest valid Parentheses
Given a string A containing just the characters '(' and ')'. Find the length of the longest valid (well-formed) parentheses substring.
Input Format:
The only argument given is string A.
Output Format:
Return the length of the longest valid (well-formed) parentheses substring.
Constraints:
1 <= length(A) <= 750000
For Example
Input 1:
    A = "(()"
Output 1:
    2
    Explanation 1:
        The longest valid parentheses substring is "()", which has length = 2.

Input 2:
    A = ")()())"
Output 2:
    4
    Explanation 2:
        The longest valid parentheses substring is "()()", which has length = 4.
*/
int Solution::longestValidParentheses(string A) {
    int m = A.length();
    vector <int> dp(m, 0);
    dp[0] = 0;
    int res = 0;
    for(int i=1; i<m; i++)
    {
        if(A[i] == ')'  && i - dp[i - 1] - 1 >= 0 && A[i - dp[i - 1] - 1] == '(' )
        {
            if(i - dp[i - 1] - 2 >= 0)
                dp[i] = dp[i-1] + 2 + dp[i - dp[i - 1] - 2];
            else
                dp[i] = dp[i-1] + 2;
            res = max(res, dp[i]);
        }
    }
    return res;
}
