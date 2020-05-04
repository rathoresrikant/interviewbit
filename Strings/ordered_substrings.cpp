/*
Ordered Substrings
You are given an array A consisting of strings. You are supposed to order the given strings in such a way that for a particular string, all strings ordered before it exist as its substrings. Each string is made up of lowercase English letters. Return an array consisting of the correct order of strings. If it is not possible to do so, return a vector consisting of one element, which is the string "NO". Input:
A: Array of strings.
Output:
Return an array consisting of the correct order of strings. If it is not possible to do so, return a vector consisting of one element, which is the string "NO".
Constraints:
Strings in A consist of lowercase English letters
1 <= size(A) <= 100
1 <= size of strings in A <= 100
Some strings might be equal
Example:
Input:
A: [abc, abcd, a, abc]

Output:
[a, abc, abc, abcd]

Input:
A: [xyz, xz, xyzzy]

Output:
[NO]
*/
bool comp(string a, string b)
{
    return (a.length() < b.length());
}
vector<string> Solution::solve(vector<string> &A) {
    sort(A.begin(), A.end(), comp);
    int n = A.size();
    vector <string> no;
    no.push_back("NO");
    for(int i=0; i<n-1; i++)
    {
        if(A[i+1].find(A[i]) == -1)
            return no;
    }
    return A;
}
