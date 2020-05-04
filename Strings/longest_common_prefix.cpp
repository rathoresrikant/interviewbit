/*
Longest Common Prefix
Problem Description
Given the array of strings A, you need to find the longest string S which is the prefix of ALL the strings in the array. Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2. For Example: longest common prefix of "abcdefgh" and "abcefgh" is "abc".


Problem Constraints
0 <= sum of length of all strings <= 1000000


Input Format
The only argument given is an array of strings A.


Output Format
Return the longest common prefix of all strings in A.


Example Input
Input 1:
A = ["abcdefgh", "aefghijk", "abcefgh"]
Input 2:
A = ["abab", "ab", "abcd"];



Example Output
Output 1:
"a"
Output 2:
"ab"



Example Explanation
Explanation 1:
Longest common prefix of all the strings is "a".
Explanation 2:
Longest common prefix of all the strings is "ab".
*/
string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size(), flag;
    char curr;
    string res;
    int m = A[0].length();
    for(int i=0; i<m; i++)
    {
        curr = A[0][i];
        flag = 0;
        for(int j=1; j<n; j++)
        {
            int p = A[j].length();
            if(p < i)
            {
                flag = 1;
                break;
            }
            if(A[j][i] != curr)
                flag = 1;
        }
        if(flag  == 0)
            res.push_back(A[0][i]);
        else
            break;
    }
    return res;
}
