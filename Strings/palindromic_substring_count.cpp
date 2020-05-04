/*
Palindromic Substrings Count
Given a string Aconsisting of lowercase English alphabets. Your task is to find how many substrings of A are palindrome. The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters. Return the count of palindromic substrings. Note: A string is palindrome if it reads the same from backward and forward.
Input Format
The only argument given is string A.
Output Format
Return the count of palindromic substrings.
Constraints
1 <= length of the array <= 1000
For Example
Input 1:
    A = "abab"
Output 1:
    6
    Explanation 1:
        6 palindromic substrings are:
        "a", "aba", "b", "bab", "a" and "b".

Input 2:
    A = "ababa"
Output 2:
    9
*/
int Solution::solve(string A)
{
    int n = A.length(), res = 0;
    for(int c=0; c<=2*n-1; c++)
    {
        int l = c/2;
        int r = l + c%2;
        while(l >= 0 && r < n && A[l] == A[r])
        {
            res++;
            l--;
            r++;
        }
    }
    return res;
}
