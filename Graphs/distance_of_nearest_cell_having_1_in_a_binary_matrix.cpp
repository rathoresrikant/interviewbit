/*
Distance of nearest cell having 1 in a binary matrix
Given a matrix of integers A of size N x M consisting of 0 or 1. For each cell of the matrix find the distance of nearest 1 in the matrix. Distance between two cells (x1, y1) and (x2, y2) is defined as |x1 - y1| + |x2 - y2|. Find and return a matrix B of size N x M which defines for each cell in A distance of nearest 1 in the matrix A. Note:
Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.
There is atleast one 1 is present in the matrix.

Input Format
The first argument given is the integer matrix A.
Output Format
Return the matrix B.
Constraints
1 <= N, M <= 1000
0 <= A[i] <= 2
For Example
Input 1:
    A = [   [0, 0, 0, 1]
            [0, 0, 1, 1]
            [0, 1, 1, 0]   ]
Output 1:
        [   [3, 2, 1, 0]
            [2, 1, 0, 0]
            [1, 0, 0, 1]   ]

Input 2:
    A = [   [1, 0, 0]
            [0, 0, 0]
            [0, 0, 0]   ]
Output 2:
        [   [0, 1, 2]
            [1, 2, 3]
            [2, 3, 4]   ]
*/
typedef pair<int,int> pi;
vector<vector<int> > Solution::solve(vector<vector<int> > &A)
{
    int rows = A.size(), cols = A[0].size();
    vector<vector<int>> distance(rows, vector<int>(cols,0));
    vector<vector<bool>> visited(rows, vector<bool>(cols,false));
    queue <pi> q;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(A[i][j] == 1)
            {
                q.push(make_pair(i,j));
                visited[i][j] = true;
            }
        }
    }
    while(!q.empty())
    {
        pi curr = q.front();
        q.pop();
        int r = curr.first, c = curr.second;
        if(r > 0 && !visited[r-1][c])
        {
            visited[r-1][c] = true;
            q.push(make_pair(r-1,c));
            distance[r-1][c] = distance[r][c] + 1;
        }
        if(c > 0 && !visited[r][c-1])
        {
            visited[r][c-1] = true;
            q.push(make_pair(r,c-1));
            distance[r][c-1] = distance[r][c] + 1;
        }
        if(r < rows-1 && !visited[r+1][c])
        {
            visited[r+1][c] = true;
            q.push(make_pair(r+1,c));
            distance[r+1][c] = distance[r][c] + 1;
        }
        if(c < cols-1 && !visited[r][c+1])
        {
            visited[r][c+1] = true;
            q.push(make_pair(r,c+1));
            distance[r][c+1] = distance[r][c] + 1;
        }
    }
    return distance;
}
