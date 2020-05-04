/*
Same Format String
Given two strings A and B. Check if B contains same characters as that of given string A and in the same order. Note
 1: A and B contain only UPPERCASE Letters.
2: No two consecutive characters are same in A.
3: You can only use constant amount of extra memory.

Input Format
The first argument given is string A.
The second argument given is string B.
Output Format
Return 1 if B contains same characters as that of given string A and in the same order else return 0.
For Example
Input 1:
    A = "HIRED"
    B = "HHHIIIRRRRREEEEEDDDDD"
Output 1:
    1

Input 2:
    A = "HIRED"
    B = "DDHHHHIIIIRRRRREEEEDDD"
Output 2:
    0
*/
int Solution::solve(const string A, const string B) {
    int n = B.length(), i, j;
    if(B[0] != A[0])
        return 0;
    for(i=1, j = 1; i<n; i++)
    {
        if(B[i] != B[i-1])
        {
            if(B[i] != A[j])
                return 0;
            else
            {
                j++;
            }
        }
    }
    if(j < A.length())
        return 0;
    return 1;
}
