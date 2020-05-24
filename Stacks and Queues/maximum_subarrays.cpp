/*
Maximum subarrays
Given an array of integers A of size N. Find and return an integer array B such that: B1 is equal to number of subarrays in which A1 is maximum. B2 is equal to number of subarrays in which A2 is maximum. B3 is equal to number of subarrays in which A3 is maximum. . . . BN is equal to number of subarrays in which AN is maximum. Since the values of B can be very large. Return B such that Bi = Bi modulo (109+7). Note: All integers in A are distinct.
Input Format
The only argument given is the integer array A.
Output Format
Return an array of integers B.
Constraints
1 <= N <= 2*10^5
1 <= A[i] <= 10^9
For Example
Input 1:
    A = [6, 11, 7, 1, 12]
Output 1:
    B = [1, 6, 2, 1, 5]

Input 2:
    A = [7, 12, 1, 11]
Output 2:
    B = [1, 6, 1, 2]
*/
long long MOD = 1e9+7;
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector <long long> left(n), right(n);
    stack <int> st;
    st.push(0);
    left[0] = -1;
    for(int i=1; i<n; i++)
    {
        if(A[i] < A[st.top()])
        {
            left[i] = st.top();
            st.push(i);
        }
        else
        {
            while(!st.empty() && A[st.top()] <= A[i])
                st.pop();
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
    }
    while(!st.empty())
        st.pop();
    right[n-1] = n;
    st.push(n-1);
    for(int i=n-2; i>=0; i--)
    {
        if(A[i] < A[st.top()])
        {
            right[i] = st.top();
            st.push(i);
        }
        else
        {
            while(!st.empty() && A[st.top()] <= A[i])
                st.pop();
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
    }
    vector <int> res(n, 0);
    for(long long i=0; i<n; i++)
    {
        res[i] = (abs(i-left[i])*abs(i-right[i]))%MOD;
    }
    return res;
}
