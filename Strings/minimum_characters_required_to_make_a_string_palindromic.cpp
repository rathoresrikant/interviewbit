/*
Minimum Characters required to make a String Palindromic
Problem Description
Given a string A of size N consisting only of uppercase alphabets. The only operation allowed is to insert characters in the beginning of the string. Find and return how many minimum characters are needed to be inserted to make the string a palindrome string.


Problem Constraints
1 <= N <= 105


Input Format
The only argument given is a string A.


Output Format
Return an integer denoting the minimum characters that are needed to be inserted to make the string a palindrome string.


Example Input
A = "ABC"


Example Output
2


Example Explanation
Insert 'B' at beginning, string becomes: "BABC".
Insert 'C' at beginning, string becomes: "CBABC".
*/
bool check(string str)
{
    int n = str.length();
    for(int i=0, j = n-1; i<=j;i++,j--)
    {
        if(str[i] != str[j])
            return false;
    }
    return true;
}
int Solution::solve(string A) {
    int m = A.length(), count = 0, flag = 0;
    while(A.length() > 0)
    {
        if(check(A))
        {
            flag = 1;
            break;
        }
        else
        {
            A.pop_back();
            count++;
        }
    }
    return count;
}
