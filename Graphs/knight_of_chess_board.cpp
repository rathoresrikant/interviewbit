/*
Knight On Chess Board
Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not. Knight's movements on a chess board The above figure details the movements for a knight ( 8 possibilities ). If yes, then what would be the minimum number of steps for the knight to move to the said point. If knight can not move from the source point to the destination point, then return -1. Note: A knight cannot go out of the board.
 Input Format:
The first argument of input contains an integer A.
The second argument of input contains an integer B.
    => The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
    => The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
    => The Knight wants to reach position (E, F).
Output Format:
If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.
Constraints:
1 <= A, B <= 500
Example
Input 1:
    A = 8
    B = 8
    C = 1
    D = 1
    E = 8
    F = 8

Output 1:
    6

Explanation 1:
    The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
    The minimum number of moves required for this is 6.
*/
typedef pair<int,int> pi;
int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    if(A == 1 && B == 1)
        return 0;
    vector<vector<int>> distance(A+1, vector <int> (B+1,0));
    vector<vector<bool>> visited(A+1, vector<bool> (B+1,false));

    vector<vector<int>> pos = {{-1,-2}, {-1,2}, {1,-2}, {1,2}, {-2,1}, {-2,-1}, {2,1}, {2,-1}};

    queue <pi> q;
    q.push({C,D});
    visited[C][D] = true;
    while(!q.empty())
    {
        pi curr = q.front();
        q.pop();
        int row = curr.first, col = curr.second;
        for(int i=0; i<pos.size(); i++)
        {
            int r_k = pos[i][0], c_k = pos[i][1];
            if(row+r_k >= 1 && row+r_k <= A && col+c_k >= 1 && col+c_k <= B && visited[row+r_k][col+c_k] == false)
            {
                visited[row+r_k][col+c_k] = true;
                distance[row+r_k][col+c_k] = distance[row][col] + 1;
                q.push({row+r_k, col+c_k});
            }
        }
    }
    if(distance[E][F] == 0)
        return -1;
    return distance[E][F];
}
