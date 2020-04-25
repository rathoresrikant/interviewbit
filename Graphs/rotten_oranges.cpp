/*
Rotten Oranges
Given a matrix of integers A of size N x M consisting of 0, 1 or 2. Each cell can have three values:
The value 0 representing an empty cell.
The value 1 representing a fresh orange.
The value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1 instead. Note:
Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.

Input Format
The first argument given is the integer matrix A.
Output Format
Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1 instead.
Constraints
1 <= N, M <= 1000
0 <= A[i] <= 2
For Example
Input 1:
    A = [   [2, 1, 1]
            [1, 1, 0]
            [0, 1, 1]   ]
Output 1:
    4

Input 2:
    A = [   [2, 1, 1]
            [0, 1, 1]
            [1, 0, 1]   ]
Output 2:
    -1
*/
int Solution::solve(vector<vector<int> > &A)
{
    int rows = A.size(), cols = A[0].size();
    vector <vector<int>> dist(rows, vector<int>(cols, 0));
    vector <vector<bool>> visited(rows, vector<bool>(cols,false));
    queue <pair<int,int>> q;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(A[i][j] == 2)
            {
                q.push(make_pair(i,j));
                dist[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    while(!q.empty())
    {
        pair<int,int> curr = q.front();
        q.pop();
        int r = curr.first, c = curr.second;
        if(r > 0 && !visited[r-1][c] && A[r-1][c] == 1)
        {
            q.push({r-1, c});
            dist[r-1][c] = dist[r][c] + 1;
            visited[r-1][c] = true;
        }
        if(c > 0 && !visited[r][c-1] && A[r][c-1] == 1)
        {
            q.push({r, c-1});
            dist[r][c-1] = dist[r][c] + 1;
            visited[r][c-1] = true;
        }
        if(r < rows-1 && !visited[r+1][c] && A[r+1][c] == 1)
        {
            q.push({r+1, c});
            dist[r+1][c] = dist[r][c] + 1;
            visited[r+1][c] = true;
        }
        if(c < cols-1 && !visited[r][c+1] && A[r][c+1] == 1)
        {
            q.push({r, c+1});
            dist[r][c+1] = dist[r][c] + 1;
            visited[r][c+1] = true;
        }
    }
    int res = INT_MIN;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(A[i][j] == 1)
            {
                if(dist[i][j] == 0)
                    return -1;
                res = max(res, dist[i][j]);
            }
        }
    }
    return res;
}
