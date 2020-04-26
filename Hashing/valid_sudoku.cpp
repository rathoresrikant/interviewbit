/*
Valid Sudoku
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx The Sudoku board could be partially filled, where empty cells are filled with the character '.'.  The input corresponding to the above configuration :
["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.
 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/
int Solution::isValidSudoku(const vector<string> &A) {
    int n = 9, m = 9;
    for(int i=0; i<n; i++)
    {
        vector <int> arr(9,0);
        for(int j=0; j<m; j++)
        {
            if(A[i][j] != '.')
            {
                arr[A[i][j]-'1']++;
                if(arr[A[i][j]-'1'] > 1)
                    return 0;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        vector <int> arr(9,0);
        for(int j=0; j<m; j++)
        {
            if(A[j][i] != '.')
            {
                arr[A[j][i] - '1']++;
                if(arr[A[j][i] - '1'] > 1)
                    return 0;
            }
        }
    }
    vector <vector <int> > mp(9, vector <int> (9));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j] != '.')
            {
            if(i >= 0 && i <= 2 && j >= 0 && j <= 2)
            {
                mp[0][A[i][j]-'1']++;
                if(mp[0][A[i][j]-'1'] > 1)
                    return 0;
            }
            if(i >= 3 && i <= 5 && j >= 0 && j <= 2)
            {
                mp[1][A[i][j]-'1']++;
                if(mp[1][A[i][j]-'1'] > 1)
                    return 0;
            }
            if(i >= 6 && i <= 8 && j >= 0 && j <= 2)
            {
                mp[2][A[i][j]-'1']++;
                if(mp[2][A[i][j]-'1'] > 1)
                    return 0;
            }
            if(i >= 0 && i <= 2 && j >= 3 && j <= 5 )
            {
                mp[3][A[i][j]-'1']++;
                if(mp[3][A[i][j]-'1'] > 1)
                    return 0;
            }
            if(i >= 3 && i <= 5 && j >= 3 && j <= 5)
            {
                mp[4][A[i][j]-'1']++;
                if(mp[4][A[i][j]-'1'] > 1)
                    return 0;
            }
            if(i >= 6 && i <= 8 && j >= 3 && j <= 5)
            {
                mp[5][A[i][j]-'1']++;
                if(mp[5][A[i][j]-'1'] > 1)
                    return 0;
            }
            if(i >= 0 && i <= 2 && j >= 6 && j <= 8)
            {
                mp[6][A[i][j]-'1']++;
                if(mp[6][A[i][j]-'1'] > 1)
                    return 0;
            }
            if(i >= 3 && i <= 5 && j >= 6 && j <= 8)
            {
                mp[7][A[i][j]-'1']++;
                if(mp[7][A[i][j]-'1'] > 1)
                    return 0;
            }
            if(i >= 6 && i <= 8 && j >= 6 && j <= 8)
            {
                mp[8][A[i][j]-'1']++;
                if(mp[8][A[i][j]-'1'] > 1)
                    return 0;
            }
            }
        }
    }
    return 1;
}
