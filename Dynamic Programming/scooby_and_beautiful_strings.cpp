/*
Scooby and Beautiful Strings
Scooby doo likes beautiful strings. Scooby doo calls a string 'S' beautiful if there exists a String 'T' such that S=T+T, where '+' represents the concatenation of the two strings. "aabaab","aa","" are some examples of beautiful strings. Now scooby gives a string s to Shaggy and and asks him to find out the longest beautiful string that can be obtained from s by erasing some of its characters. (Possibly none or in the worst case erasing all the characters). In other words scooby wants the longest beautiful string that occurs in s as a subsequence. Shaggy is a noob with strings and thus needs your help. Help Shaggy by returning the length of the longest possible beautiful string that can be obtained from given string s. Constraints: Number of testcases 1<=T<=150 Length of String 1<=s<=100 Sample Input: aabbab Sample Output: 4 Explanation: abab is the subsequence that is a beautiful string and has length 4. Therefore the answer is 4. Also it can be seen that there is no beautiful string with length greater than 4.
*/
int LCS(string A, string B)
{
    int n = A.length(), m = B.length();
    vector <vector <int> > dp(n+1, vector <int> (m+1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if(A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int Solution::getMaxLengthOfBeautifulString(string A) {
    int n = A.length(), res = 0;
    for(int i=0; i<n-1; i++)
    {
        string strA, strB;
        for(int j=0; j<=i; j++)
            strA.push_back(A[j]);
        for(int j=i+1; j<n; j++)
            strB.push_back(A[j]);
        res = max(LCS(strA, strB), res);
    }
    return res*2;
}
