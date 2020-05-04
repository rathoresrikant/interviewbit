/*
Anagram Substring Search
Given a string A and a string B. Find and return the starting indices of the substrings of A which matches any of the anagrams of B. Note: An anagram is a play on words created by rearranging the letters of the original word to make a new word or phrase
Input Format
The arguments given are string A and string B.
Output Format
Return the starting indices of the substrings of A which matches any of the anagrams of B.
Constraints
1 <= length of the string A,B <= 100000
length of string A > length of string B
'a' < = A[i] ,B[i] < ='z'
For Example
Input 1:
    A = "BACDGABCDA"
    B = "ABCD"
Output 1:
    [0, 5, 6]

Input 2:
    A = "AAABABAA"
    B = "AABA"
Output 2:
    [0, 1, 4]
*/
vector<int> Solution::solve(string A, string B) {
    int n = A.length(), m = B.length(), count = 0;
    vector <int> mpA(26,0), mpB(26,0), res;
    for(int i=0; i<m; i++)
        mpB[B[i]-'a']++;
    for(int j=0; j<m; j++)
        mpA[A[j]-'a']++;
    for(int i=0; i<26; i++)
    {
        if(mpA[i] == mpB[i])
            count++;
    }
    if(count == 26)
        res.push_back(0);
    for(int i = m, start = 0; i < n; i++)
    {
        mpA[A[start]-'a']--;
        start++;
        mpA[A[i] - 'a']++;
        count = 0;
        for(int i=0; i<26; i++)
        {
            if(mpA[i] == mpB[i])
                count++;
        }
        if(count == 26)
            res.push_back(start);
    }
    return res;
}
