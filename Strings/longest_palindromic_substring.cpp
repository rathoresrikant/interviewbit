/*
Longest Palindromic Substring
Problem Description
Given a string A of size N, find and return the longest palindromic substring in A. Substring of string A is A[i...j] where 0 <= i <= j < len(A) Palindrome string:
A string which reads the same backwards. More formally, A is palindrome if reverse(A) = A. Incase of conflict, return the substring which occurs first ( with the least starting index).


Problem Constraints
1 <= N <= 10000


Input Format
First and only argument is a string A.


Output Format
Return a string denoting the longest palindromic substring of string A.


Example Input
A = "aaaabaaa"


Example Output
"aaabaaa"


Example Explanation
We can see that longest palindromic substring is of length 7 and the string is "aaabaaa".
*/
string Solution::longestPalindrome(string A) {
    int n = A.length();
    vector <vector <bool> > dp(n, vector <bool> (n));
    int res = 1;
    for(int i=0; i<n; i++)
        dp[i][i] = true;
    int start = 0;
    for(int i=0; i<n-1; i++)
    {
        if(A[i] == A[i+1])
        {
            dp[i][i+1] = true;
            start = i;
            res = 2;
        }
    }
    for(int k=3; k<=n; k++)
    {
        for(int i=0; i<n-k+1; i++)
        {
            int j = i + k - 1;
            if(dp[i+1][j-1] && A[i] == A[j])
            {
                dp[i][j] = true;
                if(k > res)
                {
                    start = i;
                    res = k;
                }
            }
        }
    }
    string ans;
    for(int i=start; i <= start +res-1; i++)
    {
        ans.push_back(A[i]);
    }
    return ans;
}
