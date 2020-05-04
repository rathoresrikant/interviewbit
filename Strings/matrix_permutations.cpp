/*
Matrix Permutation
Given a matrix of integers A of size N x N.Find whether all rows are circular rotations of each other or not. Return "YES",if all rows of A are circular rotations of each other, else return "NO". Note: Rows are numbered from top to bottom and columns are numbered from left to right.
Input Format
The first argument given is the integer matrix A.
Output Format
Return "YES",if all rows of A are circular rotations of each other, else return "NO".
Constraints
1 <= N <= 1000
1 <= A[i] <= 100000
For Example
Input 1:
    A = [   [1, 2, 3]
            [3, 2, 1]
            [2, 3, 1]   ]
Output 1:
    NO

Input 2:
    A = [   [1, 2, 2, 1]
            [1, 1, 2, 2]
            [2, 1, 1, 2]
            [1, 1, 2, 2]    ]
Output 2:
    YES
*/
string Solution::solve(vector<vector<int> > &A)
{
    int rows = A.size(), cols = A[0].size();
    string str = "";
    for(int i=0; i<cols; i++)
    {
        str = str + "-" + to_string(A[0][i]);
    }
    str = str + str;
    for(int i=1; i<rows; i++)
    {
        string sub_str = "";
        for(int j=0; j<cols; j++)
        {
            sub_str = sub_str + "-" + to_string(A[i][j]);
        }
        if (str.find(sub_str) == string::npos)
            return "NO";
    }
    return "YES";
}
