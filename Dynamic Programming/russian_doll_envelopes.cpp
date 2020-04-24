/*
Russian Doll Envelopes
Given a matrix of integers A of size N x 2 describing dimensions of N envelopes, where A[i][0] denotes the height of the ith envelope and A[i][1] denotes the width of the ith envelope. One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope. Find the maximum number of envelopes you can put one inside other.
Input Format
The only argument given is the integer matrix A.
Output Format
Return the maximum number of envelopes you can put one inside other.
Constraints
1 <= N <= 1000
1 <= A[i][0], A[i][1] <= 10^9
For Example
Input 1:
    A = [   [5, 4]
            [6, 4]
            [6, 7]
            [2, 3]   ]
Output 1:
    3
    Explanation 1:
        Step 1: put [2, 3] inside [5, 4]
        Step 2: put [5, 4] inside [6, 7]

Input 2:
    A = A : [   [8, 9]
                [8, 18] ]
Output 2:
    1
    Explanation 2:
        No envelopes can be put inside any other so answer is 1.
*/
int Solution::solve(vector<vector<int> > &A)
{
    int n = A.size(), res = -1;
    sort(A.begin(), A.end());
    if(n == 0 || n == 1)
        return n;
    vector <int> dp(n,1);
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[i][1] > A[j][1])
            {
                if(A[i][0] != A[j][0])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
                else
                {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            if(res < dp[i])
                    res = dp[i];
        }
    }
    return res;
}
