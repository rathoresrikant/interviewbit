/*
Coins in a Line
There are A coins (Assume A is even) in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins. Assume that you go first. Return the maximum amount of money you can win. Input Format:
The first and the only argument of input contains an integer array, A.
Output Format:
Return an integer representing the maximum amount of money you can win.
Constraints:
1 <= length(A) <= 500
1 <= A[i] <= 1e5
Examples:
Input 1:
    A = [1, 2, 3, 4]

Output 1:
    6

Explanation 1:

    You      : Pick 4
    Opponent : Pick 3
    You      : Pick 2
    Opponent : Pick 1

    Total money with you : 4 + 2 = 6

Input 2:
    A = [5, 4, 8, 10]

Output 2:
    15

Explanation 2:

    You      : Pick 10
    Opponent : Pick 8
    You      : Pick 5
    Opponent : Pick 4

    Total money with you : 10 + 5 = 15
*/

int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    vector <vector <int> > dp(n, vector <int> (n));
    for(int interval=0; interval<n; interval++)
    {
        for(int i=0, j=interval; j < n; i++,j++)
        {
            int a, b, c;
            if (i + 2 <= j)
				a = dp[i + 2][j];
			else
				a = 0;
			if (i + 1 <= j - 1)
				b = dp[i + 1][j - 1];
			else
				b = 0;
			if (i <= j - 2)
				c = dp[i][j-2];
			else
				c = 0;
			dp[i][j] = max(A[i] + min(a, b), A[j]+ min(b, c));
        }
    }
    return dp[0][n- 1];
}
