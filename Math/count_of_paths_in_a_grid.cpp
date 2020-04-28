/*
Count of paths in a grid
Given an integer A, find and return the number of paths in a grid of size (A x A) that starts from (1, 1) and reaches (A, A) without crossing the major diagonal. Since the result can be large, return the result modulo (10^9 + 7). NOTE
The major diagonal of a matrix A is the collection of entries A[i][j] where i == j

Input Format
The only argument given is integer A.
Output Format
Return the number of paths modulo (10^9 + 7).
Constraints
1 <= A <= 10^6
For Example
Input 1:
    A = 2
Output 1:
    1

Input 2:
    A = 5
Output 2:
    14
*/
long long MOD = 1e9+7;
long long power(long long x, long long y, long long m)
{
    if (y == 0)
        return 1;
    long long p = power(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}
long long modInverse(long long a, long long m)
{
    return power(a, m-2, m);
}

int Solution::solve(int A) {
    long long res = 1, fact = 1;
    for(long long i =1; i<=A; i++)
    {
        fact = (fact*i)%MOD;
    }
    for(long long i = A+1; i<=2*A; i++)
    {
        res = (res*i)%MOD;
    }
    res = (((res*modInverse(fact,MOD))%MOD)*modInverse(A+1, MOD))%MOD;
    return res;
}
