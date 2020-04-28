/*
Kingdom War
Two kingdoms are on a war right now, kingdom X and kingdom Y. As a war specialist of kingdom X, you scouted kingdom Y area. A kingdom area is defined as a N x M grid with each cell denoting a village. Each cell has a value which denotes the strength of each corresponding village. The strength can also be negative, representing those warriors of your kingdom who were held hostages. There's also another thing to be noticed.
The strength of any village on row larger than one (2<=r<=N) is stronger or equal to the strength of village which is exactly above it.
The strength of any village on column larger than one (2<=c<=M) is stronger or equal to the strength of vilage which is exactly to its left. (stronger means having higher value as defined above).
So your task is, find the largest sum of strength that you can erase by bombing one sub-matrix in the grid. Input format:
First line consists of 2 integers N and M denoting the number of rows and columns in the grid respectively.
The next N lines, consists of M integers each denoting the strength of each cell.

1 <= N <= 1500
1 <= M <= 1500
-200 <= Cell Strength <= 200
Output:
The largest sum of strength that you can get by choosing one sub-matrix.
Example:
Input:
3 3
-5 -4 -1
-3 2 4
2 5 8

Output:
19

Explanation:
Bomb the sub-matrix from (2,2) to (3,3): 2 + 4 + 5 + 8 = 19
*/
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = m-2; j>=0; j--)
        {
            A[i][j] += A[i][j+1];
        }
    }
    for(int j = m-1; j >= 0; j--)
    {
        for(int i = n-2; i>=0; i--)
        {
            A[i][j] += A[i+1][j];
        }
    }
    int res = INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j] > res)
                res = A[i][j];
        }
    }
    return res;
}
