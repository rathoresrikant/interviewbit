/*
Pair Sum divisible by M
Problem Description
Given an array of integers A and an integer B, find and return the number of pairs in A whose sum is divisible by B. Since the answer may be large, return the answer modulo (109 + 7).


Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 109
1 <= B <= 106


Input Format
The first argument given is the integer array A.
The second argument given is the integer B.


Output Format
Return the total number of pairs for which the sum is divisible by B modulo (109 + 7).


Example Input
Input 1:
 A = [1, 2, 3, 4, 5]
 B = 2
Input 2:
 A = [5, 17, 100, 11]
 B = 28



Example Output
Output 1:
 4
Output 2:
 1



Example Explanation
Explanation 1:
 All pairs which are divisible by 2 are (1,3),(1,5),(2,4),(3,5).
 So total 4 pairs.
*/
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
int Solution::solve(vector<int> &A, int B) {
    long long n = A.size(), sum = 0, MOD = 1e9 + 7;
    vector <long long> count(B+1,0);
    for(long long i=0; i<n; i++)
        count[A[i]%B]++;
    if(count[0] > 1)
    sum = (((count[0]%MOD)*((count[0]-1)%MOD))*modInverse(2,MOD))%MOD;
    for(long long j=1; j < B/2; j++)
        sum = (sum%MOD +  ((count[j]%MOD)*(count[B-j]%MOD))%MOD)%MOD;
    if(B%2 == 0)
    {
        if(count[B/2] > 1)
        sum = (sum%MOD +  ((((count[B/2]%MOD)*((count[B/2]-1)%MOD))%MOD)*modInverse(2,MOD))%MOD)%MOD;
    }
    else
        sum = (sum%MOD + ((count[B/2]%MOD)*(count[(B/2)+1]%MOD))%MOD)%MOD;
    return (int)sum%MOD;
}
