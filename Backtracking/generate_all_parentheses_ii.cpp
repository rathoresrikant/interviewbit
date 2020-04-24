/*
Generate all Parentheses II
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n. For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.
*/
vector <string> res;
void fun(int start, int end, int position, int n)
{
    static char str[500];
    if(end == n)
    {
        res.push_back(str);
        return;
    }
    else
    {
        if(start < n)
        {
            str[position] = '(';
            fun(start+1, end, position+1, n);
        }
        if(start > end)
        {
            str[position] = ')';
            fun(start, end+1, position+1, n);
        }
    }
}
vector<string> Solution::generateParenthesis(int A)
{
    res.erase(res.begin(), res.end());
    fun(0, 0, 0, A);
    return res;
}
