/*
Number of islands
Given a matrix of integers A of size N x M consisting of 0 and 1. A group of connected 1's forms an island. From a cell (i, j) such that A[i][j] = 1 you can visit any cell that shares a corner with (i, j) and value in that cell is 1. More formally, from any cell (i, j) if A[i][j] = 1 you can visit:
(i-1, j) if (i-1, j) is inside the matrix and A[i-1][j] = 1.
(i, j-1) if (i, j-1) is inside the matrix and A[i][j-1] = 1.
(i+1, j) if (i+1, j) is inside the matrix and A[i+1][j] = 1.
(i, j+1) if (i, j+1) is inside the matrix and A[i][j+1] = 1.
(i-1, j-1) if (i-1, j-1) is inside the matrix and A[i-1][j-1] = 1.
(i+1, j+1) if (i+1, j+1) is inside the matrix and A[i+1][j+1] = 1.
(i-1, j+1) if (i-1, j+1) is inside the matrix and A[i-1][j+1] = 1.
(i+1, j-1) if (i+1, j-1) is inside the matrix and A[i+1][j-1] = 1.
Return the number of islands. Note:
Rows are numbered from top to bottom and columns are numbered from left to right.
Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.

Input Format
The only argument given is the integer matrix A.
Output Format
Return the number of islands.
Constraints
1 <= N, M <= 100
0 <= A[i] <= 1
For Example
Input 1:
    A = [   [0, 1, 0]
            [0, 0, 1]
            [1, 0, 0]   ]
Output 1:
    2

Input 2:
    A = [   [1, 1, 0, 0, 0]
            [0, 1, 0, 0, 0]
            [1, 0, 0, 1, 1]
            [0, 0, 0, 0, 0]
            [1, 0, 1, 0, 1]    ]
Output 2:
    5
}
int Solution::solve(vector <vector<int> > &A)
{
    int rows = A.size(), cols = A[0].size();
    if(rows == 0 || cols == 0)
        return 0;
    vector <vector <bool> > visited(rows, vector <bool> (cols, false));
    int count = 0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(A[i][j] == 1 && visited[i][j] == false)
            {
                count++;
                visited[i][j] = true;
                //cout <<"\n"<< i <<" "<< j <<" :";
                stack <pair<int, int> > q;
                q.push(make_pair(i, j));
                while(!q.empty())
                {
                    pair <int, int> p = q.top();
                    q.pop();
                    int rn = p.first, cn = p.second;
                    //cout << rn <<" "<<cn <<", ";
                    visited[rn][cn] = true;
                    if(rn > 0 && (A[rn-1][cn] == 1) && (visited[rn-1][cn] == false))
                    {
                        q.push(make_pair(rn-1, cn));
                        visited[rn-1][cn] == true;
                    }
                    if(rn > 0 && cn > 0 && (A[rn-1][cn-1] == 1) && (visited[rn-1][cn-1] == false))
                    {
                        q.push(make_pair(rn-1, cn-1));
                        visited[rn-1][cn-1] = true;
                    }
                    if(rn > 0  && cn < cols-1 && (A[rn-1][cn+1] == 1) && (visited[rn-1][cn+1] == false))
                    {
                        q.push(make_pair(rn-1, cn+1));
                        visited[rn-1][cn+1] = true;
                    }
                    if(cn > 0 && (A[rn][cn-1] == 1) && (visited[rn][cn-1] == false))
                    {
                        q.push(make_pair(rn, cn-1));
                        visited[rn][cn-1] = true;
                    }
                    if(cn < cols-1 && (A[rn][cn+1] == 1) && (visited[rn][cn+1] == false))
                    {
                        q.push(make_pair(rn, cn+1));
                        visited[rn][cn+1] = true;
                    }
                    if(rn < rows-1 && (A[rn + 1][cn] == 1) && (visited[rn+1][cn] == false))
                    {
                        q.push(make_pair(rn+1, cn));
                        visited[rn+1][cn] = true;
                    }
                    if(rn < rows-1 && cn > 0 && (A[rn+1][cn-1] == 1) && (visited[rn+1][cn-1] == false))
                    {
                        q.push(make_pair(rn+1, cn-1));
                        visited[rn+1][cn-1] = true;
                    }
                    if(rn < rows-1 && cn < cols-1 && (A[rn+1][cn+1] == 1) && (visited[rn+1][cn+1] == false))
                    {
                        q.push(make_pair(rn+1, cn+1));
                        visited[rn+1][cn+1] = true;
                    }
                }
            }
        }
    }
    return count;
}
