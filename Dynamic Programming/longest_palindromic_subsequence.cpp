/*
Longest Pallindromic Subsequence
Given a strings A. Find the common pallindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself You need to return the length of such longest common subsequence. NOTE:
Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.
CONSTRAINTS
1 <= Length of A, B <= 10^3 + 5
EXAMPLE INPUT
A : "bebeeed"
EXAMPLE OUTPUT
4
EXPLANATION
The longest common pallindromic subsequence is "eeee", which has a length of 4
*/
int Solution::solve(string A) {
    int n = A.length();
    vector <vector <int> > dp(n, vector <int> (n));
    for(int i=0; i<n; i++)
    {
        dp[i][i] = 1;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<n-i+1; j++)
        {
            int k = i + j - 1;
            if(i == 2 && A[j] == A[k])
            {
                dp[j][k] = 2;
            }
            else
            if(A[j] == A[k])
            {
                dp[j][k] = dp[j+1][k-1] + 2;
            }
            else
            {
                dp[j][k] = max(dp[j+1][k], dp[j][k-1]);
            }
        }
    }
    return dp[0][n-1];
}
