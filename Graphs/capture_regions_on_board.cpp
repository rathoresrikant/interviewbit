/*
Capture Regions on Board
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'. A region is captured by flipping all 'O's into 'X's in that surrounded region. Input Format:
    First and only argument is a N x M character matrix A
Output Format:
    make changes to the the input only as matrix is passed by reference.
Constraints:
    1 <= N,M <= 1000
For Example:
Input 1:
    A = [ [X, X, X, X],
          [X, O, O, X],
          [X, X, O, X],
          [X, O, X, X] ]
Output 1:
    After running your function, the board should be:
    A = [ [X, X, X, X],
          [X, X, X, X],
          [X, X, X, X],
          [X, O, X, X] ]
Explanation:
    O in (4,2) is not surrounded by X from below.
*/
vector <pair<int, int> > temp;
bool DFS(int i, int j, vector<vector<char>> &board, vector <vector<bool>> &visited)
{
    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return false;
    if(board[i][j] == 'X')
    {
        visited[i][j] = true;
        return true;
    }
    if(visited[i][j] == true)
        return true;
    temp.push_back(make_pair(i, j));
    visited[i][j] = true;
    bool r1 = DFS(i+1, j, board, visited);
    bool r2 = DFS(i, j+1, board, visited);
    bool r3 = DFS(i, j-1, board, visited);
    bool r4 = DFS(i-1, j, board, visited);
    return (r1 && r2 && r3 && r4);
}
void Solution::solve(vector<vector<char> > &board)
{
    int rows = board.size();
    if(rows == 0)
        return;
    int cols = board[0].size();
    vector <vector<bool>> visited(rows, vector <bool> (cols, false));
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(board[i][j] == 'O' && visited[i][j] == false)
            {
                temp.clear();
                bool flag = DFS(i, j, board, visited);
                if(flag == true)
                {
                    for(int k=0; k<temp.size(); k++)
                        board[temp[k].first][temp[k].second] = 'X';
                }
            }
        }
    }
}
