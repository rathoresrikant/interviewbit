/*
Sub-matrix Sum Queries
Given a matrix of integers A of size N x M and multiple queries Q, for each query find and return the submatrix sum. Inputs to queries are top left (b, c) and bottom right (d, e) indexes of submatrix whose sum is to find out. Note: Rows are numbered from top to bottom and columns are numbered from left to right. Sum may be large so return the answer mod 10^9 + 7.
Input Format
The first argument given is the integer matrix A.
The second argument given is the integer array B.
The third argument given is the integer array C.
The fourth argument given is the integer array D.
The fifth argument given is the integer array E.
(B[i], C[i]) represents the top left corner of the i'th query.
(D[i], E[i]) represents the bottom right corner of the i'th query.
Output Format
Return the submatrix sum (% 10^9 + 7) for each query in the form of an integer array.
Constraints
1 <= N, M <= 1000
-100000 <= A[i] <= 100000
1 <= Q <= 100000
1 <= B[i] <= D[i] <= N
1 <= C[i] <= E[i] <= M
For Example
Input 1:
    A = [   [1, 2, 3]
            [4, 5, 6]
            [7, 8, 9]   ]
    B = [1, 2]
    C = [1, 2]
    D = [2, 3]
    E = [2, 3]
Output 1:
    [12, 28]

Input 2:
    A = [   [5, 17, 100, 11]
            [0, 0,  2,   8]    ]
    B = [1, 1]
    C = [1, 4]
    D = [2, 2]
    E = [2, 4]
Output 2:
    [22, 19]
*/

vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    long long n = A.size(), m = A[0].size(), a, b, c, d, ans, mod = 1e9 + 7;
    vector <int> res;
    vector <vector <long long> > table(n+2, vector <long long> (m+2));
    for(int i=0; i<n; i++)
        for(int j=1; j<m; j++)
            A[i][j] = (A[i][j]%mod +  A[i][j-1]%mod + mod)%mod;

    for(int i=1; i<n; i++)
        for(int j=0; j<m; j++)
             A[i][j] = (A[i][j]%mod + A[i-1][j]%mod + mod)%mod;

    for(int i=1; i<=n; i++)
    {
        for(int j=1;j<=m; j++)
        {
            table[i][j] = (A[i-1][j-1] + mod)%mod;
        }
    }
    /*
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }  */
    int query = B.size();
    for(int i=0; i<query; i++)
    {
        a = B[i] , b = C[i], c = D[i], d = E[i];
        ans = (table[c][d] - table[a-1][d] + table[a-1][b-1] - table[c][b-1] + mod)%mod;
        res.push_back((ans+mod)%mod);
    }
    return res;
}
