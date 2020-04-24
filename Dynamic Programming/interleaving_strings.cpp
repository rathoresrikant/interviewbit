/*
Interleaving Strings
Given A, B, C, find whether C is formed by the interleaving of A and B. Input Format:*
The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:
Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:
1 <= length(A), length(B), length(C) <= 150
Examples:
Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1

Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.
*/

int Solution::isInterleave(string A, string B, string C)
{
    int n1 = A.length(), n2 = B.length(), n3 = C.length();
        if(n1 + n2 != n3)
                return false;
        vector <vector <bool> > dp(n1+1, vector <bool> (n2+1));
        for(int i=0; i<=n1; i++)
        {
            for(int j=0; j<=n2; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = true;
                }
                else
                if(i == 0)
                {
                    dp[i][j] = (dp[i][j-1] && B[j-1] == C[i+j-1]);
                }
                else
                if(j == 0)
                {
                    dp[i][j] = (dp[i-1][j] && A[i-1] == C[i+j-1]);
                }
                else
                {
                    dp[i][j] = ((dp[i-1][j] && A[i-1] == C[i+j-1]) ||
                        (dp[i][j-1] && B[j-1] == C[i+j-1]));
                }
            }
        }
        return dp[n1][n2];
}
