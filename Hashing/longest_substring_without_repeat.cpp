/*
Longest Substring Without Repeat
Problem Description
Given a string A, find the length of the longest substring without repeating characters.


Problem Constraints
0 <= size(A) <= 106 String consists of lowerCase,upperCase characters and digits are also present in the string A.


Input Format
Single Argument representing string A.


Output Format
Single integer denoting the maximum possible length of substring without repeating characters.


Example Input
 A = "abcabcbb"


Example Output
3


Example Explanation
Substring "abc" is the longest substring without repeating characters in string A.
*/
int Solution::lengthOfLongestSubstring(string A)
{
    int n = A.length();
    unordered_map <char, int> mp;
    int res = 0;
    for(int i=0,j=0; j<n;)
    {
        if(mp[A[j]] == 0)
        {
            res = max(res, j-i+1);
            mp[A[j]]++;
            j++;
        }
        else
        {
            while(A[i] != A[j])
            {
                mp[A[i]]--;
                i++;
            }
            i++;
            j++;
        }
    }
    return res;
}
