Sudoku
Problem Description
Write a program to solve a Sudoku puzzle by filling the empty cells. Empty cells are indicated by the character '.' You may assume that there will be only one unique solution.


Problem Constraints
1 <= N <= 9


Input Format
First argument is an array of array of characters representing the Sudoku puzzle.


Output Format
Modify the given input to the required answer.


Example Input
Input 1:
A = [[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]



Example Output
Output 1:
[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]



Example Explanation
Explanation 1:
Look at the diagrams given in the question.

bool check(vector<vector<char>> A, int r, int c, int val)
{
    for(int i=0; i<9; i++)
    {
        if(A[i][c] == val || A[r][i] == val)
            return false;
    }
    int sr = r - r%3, sc = c - c%3;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(A[sr+i][sc+j] == val)
                return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &A, int r, int c)
{
    if(r == 9)
        return true;
    if(c == 9)
        return solve(A, r+1, 0);
    if(A[r][c] != '.')
        return solve(A, r, c+1);

    for(char i = '1'; i <= '9'; i++)
    {
        if(check(A, r, c, i))
        {
            A[r][c] = i;
            if(solve(A, r, c+1))
                return true;
            A[r][c] = '.';
        }
    }

    return false;
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    solve(A, 0, 0);
}
