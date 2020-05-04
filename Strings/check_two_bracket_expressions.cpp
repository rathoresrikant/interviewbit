/*
Check two bracket expressions
Given two strings A and B. Each string represents an expression consisting of lowercase english alphabets, '+', '-' and '()'. The task is to compare them and check if they are similar. If they are similar return 1 else return 0. Note: It may be assumed that there are at most 26 operands from ‘a’ to ‘z’ and every operand appears only once.
Input Format
The arguments given are string A and String B.
Output Format
Return 1 if they represent the same expression
else return 0.
Constraints
1 <= length of the each String <= 100
For Example
Input 1:
     A = "-(a+b+c)"
     B = "-a-b-c"
Output 1:
     1

Input 2:
     A = "a-b-(c-d)"
     B = "a-b-c-d"
Output 2:
    0
*/
string simplify(string A)
{
    string res = "";
    int n = A.length(), sign = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] == '-')
        {
            sign = abs(1-sign);
        }
        else
        if(isalpha(A[i]))
        {
            if(sign == 0)
            {
                res.push_back('+');
            }
            else
            {
                res.push_back('-');
            }
            res.push_back(A[i]);
        }
    }
    return res;
}
int Solution::solve(string A, string B)
{
    string resA = simplify(A);
    string resB = simplify(B);
    if(resA == resB)
        return 1;
    else
        return 0;
}
