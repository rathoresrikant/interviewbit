/*
Longest Common Subsequence
Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings. You need to return the length of such longest common subsequence. NOTE:
Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.
CONSTRAINTS
1 <= Length of A, B <= 10^3 + 5
EXAMPLE INPUT
A : "abbcdgf"
B : "bbadcgf"
EXAMPLE OUTPUT
5
EXPLANATION
The longest common subsequence is "bbcgf", which has a length of 5
*/
int Solution::solve(string A, string B) {
    int n = A.length(), m = B.length();
    vector <vector <int> > dp(n+1, vector <int> (m+1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j == 0)
                dp[i][j] = 0;
            else
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}
