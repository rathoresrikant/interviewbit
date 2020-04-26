/*
Set Matrix Zeros
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0. Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.
 Input Format:
The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:
Return a 2-d matrix that satisfies the given conditions.
Constraints:
1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:
Input 1:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]
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
            if(A[i][j] != '.')
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
void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size(), m = A[0].size();
    vector <int> row(n,0), col(m,0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(row[i] == 1 || col[j] == 1)
            A[i][j] = 0;
        }
    }
}
