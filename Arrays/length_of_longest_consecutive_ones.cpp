/*
Length of longest consecutive ones
Given a binary string A. It is allowed to do at most one swap between any 0 and 1. Find and return the length of the longest consecutive 1’s that can be achieved.
Input Format
The only argument given is string A.
Output Format
Return the length of the longest consecutive 1’s that can be achieved.
Constraints
1 <= length of string <= 1000000
A contains only characters 0 and 1.
For Example
Input 1:
    A = "111000"
Output 1:
    3

Input 2:
    A = "111011101"
Output 2:
    7
*/

int Solution::solve(string A) {
    int m = A.length();
    vector <int> left(m, 0), right(m, 0);
    int ones = 0, maxm = 0, temp = 0;
    for(int i=0; i<m; i++)
    {
        if(A[i] == '1')
        {
            ones++;
            temp++;
        }
        else
        {
            maxm = max(maxm, temp);
            temp = 0;
        }
    }
    maxm = max(temp, maxm);
    if(A[0] == '1')
        left[0] = 1;
    else
        left[0] = 0;
    for(int i=1; i<m; i++)
    {
        if(A[i] == '1')
            left[i] = left[i-1] + 1;
        else
            left[i] = 0;
    }
    if(A[m-1] == '1')
        right[m-1] = 1;
    else
        right[m-1] = 0;
    for(int i=m-2; i>=0; i--)
    {
        if(A[i] == '1')
            right[i] = right[i+1] + 1;
        else
            right[i] = 0;
    }
    for(int i=m-2; i>=0; i--)
    {
        if(A[i] == '0')
        {
            if(left[i-1] + right[i+1] < ones)
            {
               maxm =  max(maxm, left[i-1] + right[i+1] + 1);
            }
            else
            {
                maxm = max(maxm, left[i-1] + right[i+1]);
            }
        }
    }
    return maxm;
}
