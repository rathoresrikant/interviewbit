/*
Reduce the string
Given a string A consisting of lowercase English alphabets. Reduce the string to its shortest length by doing any number of operations (possibly zero). In one operation selects a pair of adjacent letters in the string that match and deletes them. For example the string bcaa is shortened to bc in one operation. Find and return the string by reducing it to its shortest length. if the resultant string is empty return "empty".
Input Format
The only argument given the string A.
Output Format Return the string by reducing it to its shortest length. if the resultant string is empty return "empty". Constraints
1 <= length of the string <= 1000000
For Example
Input 1:
    A = "aaabccddd"
Output 1:
    "abd"

Input 2:
    A = baab
Output 2:
    "empty"
*/
string Solution::solve(string A) {
    int m = A.length();
    stack <char> s;
    string res;
    for(int i=0; i<m; i++)
    {
        if(s.empty() == true)
            s.push(A[i]);
        else
        if(s.top() == A[i])
            s.pop();
        else
        if(s.top() != A[i])
            s.push(A[i]);
    }
    while(!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(), res.end());
    if(res.length() != 0)
        return res;
    else
        return "empty";
}
