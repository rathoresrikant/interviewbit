/*
Regroup 0's and 1's using Minimum Swaps
Given a string S, count minimum no. of swaps needed to regroup 0's and 1's. After all swaps final string will look like all 0's followed by all 1's or all 1's followed by all 0's. Swap operation swaps two adjacent characters (01 -> 10, 10 -> 01, 00 -> 00 and 11 -> 11). Note:
 Try to solve the problem using constant extra space. Expected time complexity is worst case O(length of S).
Examples: S: 000111 Answer: 0 S: 1110101 Answer: 3 Explanation: 1110101 -> 1111001 -> 1111010 -> 1111100
*/
int Solution::solve(const string A) {
    int n = A.length(), res1 = 0, res2 = 0, zero = 0, one = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] == '0')
            zero++;
        else
            one++;
    }
    for(int i=0; i<n; i++)
    {
        if(A[i] == '0')
        {
            zero--;
            res1 += one;
        }
        else
        {
            one--;
            res2 += zero;
        }
    }
    return min(res1, res2);
}
