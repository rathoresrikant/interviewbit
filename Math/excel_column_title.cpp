/*
Excel Column Title
Problem Description
Given a positive integer A, return its corresponding column title as appear in an Excel sheet. For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB



Problem Constraints
1 <= A <= 109


Input Format
First and only argument of input contains single integer A


Output Format
Return a string denoting the corresponding title.


Example Input
 A = 27


Example Output
 "AA"


Example Explanation
    1 -> A,
    2 -> B,
    3 -> C,
    ...
    26 -> Z,
    27 -> AA,
    28 -> AB
*/
string Solution::convertToTitle(int A) {
    int rem;
    string str;
    while(A>0)
    {
        rem = A%26;
        if (rem==0)
        {
           str.push_back('Z');
           A = A/26 -1;
        }
        else
        {
           str.push_back('A' + A%26 - 1);
           A = A/26;
        }
    }
    reverse(str.begin(), str.end());
    return str;
}
