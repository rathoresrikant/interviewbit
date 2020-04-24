/*
Tiling Problem
Given a 2 x A board and tiles of size 2 x 1. Count the number of ways to tile the given board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. Since the number of ways can be very large, return the number of ways modulo (109+7).
Input Format
The only argument given is an integer A.
Output Format
Return the number of ways to tile the given board modulo (10^9+7).
Constraints
1 <= A <= 10^6
For Example
Input 1:
    A = 3
Output 1:
    3
    Explanation 1:
        We need 3 tiles to tile the board of size  2 x 3.
        We can tile the board using following ways
            1. Place all 3 tiles vertically.
            2. Place first tile vertically and remaining 2 tiles horizontally.
            3. Place first 2 tiles horizontally and remaining tiles vertically

Input 2:
    A = 4
Output 2:
    5
    Explanation 2:
        For a 2 x 4 board, there are 5 ways
            1. All 4 vertical
            2. All 4 horizontal
            3. First 2 vertical, remaining 2 horizontal
            4. First 2 horizontal, remaining 2 vertical
            5. Corner 2 vertical, middle 2 horizontal
*/
int Solution::solve(int A) {
    long long MOD = 1e9 + 7;
    vector <int> dp(A);
    dp[0] = 1, dp[1] = 2;
    for(int i=2; i<A; i++)
        dp[i] = (dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
    return dp[A-1]%MOD;
}
