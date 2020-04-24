/*
Toeplitz Matrix
Given a matrix of integers A of size N x M. You have to whether the given matrix is Toeplitz or not.
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
Return 1 if the matrix is Toeplitz else return 0.
Input Format
The first argument given is the integer matrix A.
The second argument given is integer B.
Output Format
Return 1 if the matrix is Toeplitz else return 0.
Constraints
1 <= N, M <= 500
0 <= A[i] <= 10^9
For Example
Input 1:
    A =[    [1, 2, 3, 4]
            [5, 1, 2, 3]
            [9, 5, 1, 2]   ]
Output 1:
    1
    Explanation 1:
        Diagonal 1: [9]
        Diagonal 2: [5, 5]
        Diagonal 3: [1, 1, 1]
        Diagonal 4: [2, 2, 2]
        Diagonal 5: [3, 3]
        Diagonal 6: [4]

Input 2:
    A = [   [5, 6, 6, 8]
            [0, 5, 6, 8]
            [8, 0, 5, 6] ]
Output 2:
    0
*/

int Solution::solve(vector<vector<int> > &A) {
    unordered_map <int, int> mp;
    int row = A.size(), col = A[0].size();
    int idx = max(row, col), element;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            element = A[i][j];
            if(mp[i-j+idx] == 0)
            {
                mp[i-j+idx] = element;
            }
            else
            {
                if(mp[i-j+idx] != element)
                    return 0;
            }
        }
    }
    return 1;
}
