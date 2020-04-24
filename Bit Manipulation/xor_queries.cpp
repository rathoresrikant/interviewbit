/*
Xor queries
Problem Description
You are given an array A (containing only 0 and 1) as element of N length. Given L and R, you need to determine value of XOR of all elements from L to R (both inclusive) and number of unset bits (0's) in the given range of the array.


Problem Constraints
1<=N,Q<=100000
1<=L<=R<=N


Input Format
First argument contains the array of size N containing 0 and 1 only.
Second argument contains a 2D array with Q rows and 2 columns, each row represent a query with 2 columns representing L and R.


Output Format
Return an 2D array of Q rows and 2 columns i.e the xor value and number of unset bits in that range respectively for each query.


Example Input
A=[1,0,0,0,1]
B=[ [2,4],
    [1,5],
    [3,5] ]


Example Output
[[0 3]
[0 3]
[1 2]]


Example Explanation
In the given case the bit sequence is of length 5 and the sequence is 1 0 0 0 1.
For query 1 the range is (2,4), and the answer is (array[2] xor array[3] xor array[4]) = 0, and number of zeroes are 3, so output is 0 3.
Similarly for other queries.
*/

vector<vector<int> > Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size(), row = B.size(), col = B[0].size(), start, end, setbits, unsetbits, xorr;
    vector <int> sum(n,0);
    vector <vector <int> > res(row, vector <int> (col));
    sum[0]  = A[0];
    for(int i=1; i<n; i++)
        sum[i] = A[i] +  sum[i-1];
    for(int i=0; i<row; i++)
    {
        start = B[i][0] - 1, end = B[i][1] - 1;
        if(start != 0)
        setbits = sum[end] - sum[start - 1];
        else
        setbits = sum[end];
        unsetbits = (end - start + 1) - setbits;
        if(setbits%2 == 1)
            xorr = 1;
        else
            xorr = 0;
        res[i][0] = xorr;
        res[i][1] = unsetbits;
    }
    return res;
}
