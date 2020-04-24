/*
Max Rectangle in Binary Matrix
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. Bonus if you can solve it in O(n^2) or less. Example :
A : [  1 1 1
       0 1 1
       1 0 0
    ]

Output : 4

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)
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
int Solution::maximalRectangle(vector<vector<int> > &A)
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
