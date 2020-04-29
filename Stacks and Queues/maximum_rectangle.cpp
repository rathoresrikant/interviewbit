/*
Maximum Rectangle
Given a 2D binary matrix of integers A containing 0's and 1's of size N x M. Find the largest rectangle containing only 1's and return its area. Note: Rows are numbered from top to bottom and columns are numbered from left to right.
Input Format
The only argument given is the integer matrix A.
Output Format
Return the area of the largest rectangle containing only 1's.
Constraints
1 <= N, M <= 1000
0 <= A[i] <= 1
For Example
Input 1:
    A = [   [0, 0, 1]
            [0, 1, 1]
            [1, 1, 1]   ]
Output 1:
    4

Input 2:
    A = [   [0, 1, 0, 1]
            [1, 0, 1, 0]    ]
Output 2:
    1
*/
int Histogram(vector <int> &A)
{
    int n = A.size(), curr = 0, res = 0;
    stack <int> st;
    int i = 0;
    while(i < n)
    {
        if(st.empty() == true || A[st.top()] <= A[i])
        {
            st.push(i);
            i++;
        }
        else
        if(A[st.top()] > A[i])
        {
            int idx = st.top();
            st.pop();
            if(st.empty())
                curr = A[idx]*i;
            else
                curr = A[idx]*(i - st.top() - 1);
            res = max(res, curr);
        }
    }
    while(!st.empty())
    {

            int idx = st.top();
            st.pop();
            if(st.empty())
                curr = A[idx]*i;
            else
                curr = A[idx]*(i - st.top() - 1);
            res = max(res, curr);
    }
    return res;
}
int Solution::solve(vector<vector<int> > &A)
{
    int n = A.size(), m = A[0].size();
    vector <int> res(m,0);
    for(int i=0; i<m; i++)
        res[i] = A[0][i];
    int curr = Histogram(res);
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j] == 0)
                res[j] = 0;
            else
                res[j] += 1;
        }
        curr = max(curr, Histogram(res));
    }
    return curr;
}
