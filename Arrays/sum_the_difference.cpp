/*
Sum the Difference
Problem Description
Given an integer array A of size N. You have to find all possible non-empty subsequence of the array of numbers and then, for each subsequence, find the difference between the largest and smallest numbers in that subsequence Then add up all the differences to get the number. As the number may be large, output the number modulo 1e9 + 7 (1000000007). NOTE: Subsequence can be non-contiguous.


Problem Constraints
1 <= N <= 10000 1<= A[i] <=1000


Input Format
First argument is an integer array A.


Output Format
Return an integer denoting the output.


Example Input
A = [1, 2]


Example Output
1


Example Explanation
All possible non-empty subsets are:
[1]    largest-smallest = 1 - 1 = 0
[2]    largest-smallest = 2 - 2 = 0
[1 2]  largest-smallest = 2 - 1 = 1
Sum of the differences = 0 + 0 + 1 = 1
So, the resultant number is 1
*/

long long power(long long a, long long b, long long m)
{
    if(b == 0)
        return 1;
    if(b%2 == 0)
        return (power(a, b/2, m)*power(a, b/2, m))%m;
    else
        return (a*power(a, b/2, m)*power(a, b/2, m))%m;
}
int Solution::solve(vector<int> &A) {
    long long n = A.size(), res = 0, MOD = 1e9 + 7, base = 2, count;
    sort(A.begin(), A.end());
    for(long long i=0; i<n-1; i++)
    {
        for(long long j=i+1; j<n; j++)
        {
            count = power(base, j - i -1, MOD);
            res = (res%MOD + ((A[j]-A[i])*count)%MOD)%MOD;
        }
    }
    return res%MOD;
}
