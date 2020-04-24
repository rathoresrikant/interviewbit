/*
Pascal Triangle
Given numRows, generate the first numRows of Pascal's triangle. Pascal's triangle : To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1. Example: Given numRows = 5, Return
[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
*/

vector<vector<int> > Solution::solve(int A) {

    int n = A, prev, col, m;
    vector < vector<int> >  arr(n);
    if(A == 0)
        return arr;
    arr[0] = vector <int> (1);
    arr[0][0] = 1;
    prev = 0;
    for(int i=1; i<n; i++)
    {
        m = arr[prev].size();
        col = m + 1;
        arr[i] = vector <int> (col);
        arr[prev+1][0] = arr[prev][0];
        for(int i=1; i<m; i++)
            arr[prev+1][i] = (arr[prev][i] + arr[prev][i-1]);
        arr[prev+1][m] = arr[prev][m-1];
        prev++;
    }
    return arr;
}
