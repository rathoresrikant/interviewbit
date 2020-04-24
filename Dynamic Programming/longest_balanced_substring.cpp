/*
Longest Balanced Substring
Given a string S made up of multiple brackets of type "<>" , "[]" , "()" and "{}" find the length of the longest substring which forms a balanced string . Conditions for a string to be balanced : 1) Blank string is balanced ( However blank string will not be provided as a test case ). 2) if B is balanced : (B) , [B] , {B} and <B> are also balanced. 3) if B1 and B2 are balanced then B1B2 i.e the string formed by concatenating B1 and B2 is also balanced. Your function will get exactly one argument which would represent the string S. Your function should return an integer corresponding to the answer. Constraints :
0 <= length(S) <= 1000000
Sample Test Case :
Input : <<<<>
Output : 2
*/
bool isBalanced(char A, char B)
{
    if((A == '{' && B == '}') || (A == '(' && B == ')') || (A == '[' && B == ']') || (A == '<' && B == '>'))
        return true;
    else
        return false;
}
int Solution::LBSlength(const string A)
{
    int n = A.length(), res = 0;
    vector <int> dp(n+1,0);
    for(int i=1; i<=n; i++)
    {
        if(A[i-1] == '(' || A[i-1] == '{' || A[i-1] == '[' || A[i-1] == '<')
        {
            dp[i] = 0;
        }
        else
        {
            if(i > 1)
            {
                if(isBalanced(A[i-2], A[i-1]))
                {
                    dp[i] = dp[i-2] + 2;
                    res = max(res, dp[i]);
                }
                else
                {
                    int s = dp[i-1] + 1;
                    if(i >= s+1 && isBalanced(A[i-s-1],A[i-1]))
                    {
                        dp[i] = s + 1 + dp[i-s-1];
                        res = max(res, dp[i]);
                    }
                }
            }
        }
    }
    return res;
}
