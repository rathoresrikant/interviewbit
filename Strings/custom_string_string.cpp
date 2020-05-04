/*
Custom Sort String
Given two string A and B, both consisting of lowercase letters. A consists of uniques lowercase English letter i.e. no characters occur twice in it. A was sorted in some custom order previously. We want to permute the characters of B so that they match the order that A was sorted. More specifically, if character x occurs before y in A, then x should occur before y in the returned string. For the elements not present in A, append them at last in lexicographical order. Return the permutation of string B that matches the above criteria.
 Input Format
The First argument given is String A.
The Second argument given is String B.
Output Format
Return the permutation of string B that matches the given criteria.
Constraints
1 <= length of the string B <= 100000
1 <= length of the string A <= 26
For Example
Input 1:
    A = "cda"
    B = "abcd"
Output1:
    "cdab"
    Explanation 1:
        character 'c' should occur before 'a' and 'd'.
        character 'd' should occur before 'a'
        character 'b' is not present in A therefore it is appended at the end.

Input 2:
    A = "erhdqo"
    B = "wwdybr"
Output2:
    "rdbwwy"
*/
string Solution::solve(string A, string B)
{
    int na = A.length(), nb = B.length();
    vector <int> table(26,0);
    string res = "";
    for(int i=0; i<nb; i++)
        table[B[i]-'a']++;
    for(int i=0; i<na; i++)
    {
        while(table[A[i]-'a'] > 0)
        {
            table[A[i]-'a']--;
            res.push_back(A[i]);
        }
    }
    for(int i=0; i<26; i++)
    {
        while(table[i] != 0)
        {
            res.push_back(i+'a');
            table[i]--;
        }
    }
    return res;
}
