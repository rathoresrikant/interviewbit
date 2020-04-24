/*
Minimum Number of Squares
Given an integer N. Return count of minimum numbers, sum of whose squares is equal to N. Example: N=6 Possible combinations are :
(12 + 12 + 12 + 12 + 12 + 12)
(12 + 12 + 22)
So, minimum count of numbers is 3 (i.e. 1,1,2). Note: 1 ≤ N ≤
*/
int Solution::countMinSquares(int A) {
    vector<int> dp(A + 1, A);
        dp[0] = 0;
        for (int j = 0; j < A + 1; j++) {
            for (int i = 1; i * i <= A; i++) {
                if (i * i <= j) {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
    return dp[A];
}
