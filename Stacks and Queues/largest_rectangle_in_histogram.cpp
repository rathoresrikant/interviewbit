/*
Largest Rectangle in Histogram
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1. Largest Rectangle in Histogram: Example 1 Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3]. Largest Rectangle in Histogram: Example 2 The largest rectangle is shown in the shaded area, which has area = 10 unit. Find the area of largest rectangle in the histogram.
Input Format
The only argument given is the integer array A.
Output Format
Return the area of largest rectangle in the histogram.
For Example
Input 1:
    A = [2, 1, 5, 6, 2, 3]
Output 1:
    10
    Explanation 1:
        The largest rectangle is shown in the shaded area, which has area = 10 unit.
*/
int Solution::largestRectangleArea(vector<int> &A) {
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
