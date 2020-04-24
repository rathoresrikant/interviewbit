/*
Number of sextuplets (or six values) that satisfy an equation
Given an array of integers A, find the number of sextuplets that satisfy the equation (a * b + c) / d - e = f.
where a, b, c, d, e, f belong to the given array A.
Note: Since the answer can be very large, return the number of ways modulo (109 + 7).
Input Format
The only argument given is the integer array A.
Output Format
Return the find the number of sextuplets that satisfy the equation.
Constraints
1 <= length of the array <= 100
-10^6 <= A[i] <= 10^6
All elmemts of array A are distinct.
For Example
Input 1:
    A = [1]
Output 1:
    1
    a = b = c = d = e = f = 1 satisfy the equation.

Input 2:
    A = [1, -1]
Output 2:
    24
*/


int Solution::solve(vector<int> &A) {
    long long n = A.size(), res = 0, MOD = 1e9+7;
    long long temp[n*n*n + 1];
    long long idx = 0;
    unordered_map <long long, int> mp;
    for(int i=0; i<n; i++)
    {
        if(A[i])
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    mp[1LL*(A[i]*(A[j] + A[k]))]++;
                }
            }
        }
    }
    sort(temp, temp + idx);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                long long x = A[i]*A[j] + A[k];
                res += mp[x];
                while(res >= MOD)
                    res = res - MOD;
            }
        }
    }
    return (int)res;
}
