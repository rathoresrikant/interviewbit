/*
Find subsequence
Given two strings A and B, find if A is a subsequence of B. Return "YES" if A is a subsequence of B, else return "NO".
Input Format
The first argument given is the string A.
The second argument given is the string B.
Output Format
Return "YES" if A is a subsequence of B, else return "NO".
Constraints
1 <= lenght(A), length(B) <= 100000
'a' <= A[i], B[i] <= 'z'
For Example
Input 1:
    A = "bit"
    B = "dfbkjijgbbiihbmmt"
Output 1:
    YES

Input 2:
    A = "apple"
    B = "appel"
Output 2:
    "NO"
*/
string Solution::solve(string A, string B) {
    int n = A.length(), m = B.length(), match = 0, i, j;
    for(i=0, j =0; i<m; i++)
    {
        if(A[j] == B[i])
            j++;
        if(j == n)
        break;
    }
    if(j == n)
        return "YES";
    else
        return "NO";
}
