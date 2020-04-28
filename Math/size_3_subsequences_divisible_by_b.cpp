/*
Size three subsequences divisible by B
Given an array of integers A and an integer B. Find and return the number of subsequences of length 3 whose sum is divisible by B. Since the total number of subsequences may be very large. Return the total number of subsequences of length 3 whose sum is divisible by B modulo (109+7).
Input Format
The only argument given is the integer array A.
Output Format
Return the number of subsequences of length 3 whose sum is divisible by B modulo (10^9+7).
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9
1 <= B <= 10^3
For Example
Input 1:
    A = [6, 1, 1, 4, 1, 5, 3]
    B = 2
Output 1:
    20

Input 2:
    A = [4, 10, 9]
    B = 5
Output 2:
    0
*/
long long power(long long x, long long y, long long m) {
    if (y == 0)
        return 1;
    long long p = power(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}
long long modInverse(long long a, long long m){
    return power(a, m-2, m);
}

int Solution::solve(vector<int> &A, int B) {
    long long n = A.size(), k, ans = 0, MOD = 1e9+7;
    vector <int> count(B+1,0);
    for(int i=0; i<n; i++)
        count[A[i]%B]++;

    for(int i=0; i<B; i++){
        for(int j=i; j<B; j++){
            k = (B - (i+j)%B)%B;
            if(k < j)
                continue;
            if(i == j && j == k)
                ans += ((count[i]%MOD)*((count[i]-1)%MOD)*((count[i]-2)%MOD)*modInverse(6, MOD))%MOD;
            else
            if(i == j)
                ans += (((((count[i]*(count[i]-1))%MOD)*modInverse(2,MOD))%MOD)*count[k])%MOD;
            else
            if(j == k)
                ans += (((((count[j]*(count[j]-1))%MOD)*modInverse(2,MOD))%MOD)*count[i])%MOD;
            else
            if(i == k)
                ans += (((((count[i]*(count[i]-1))%MOD)*modInverse(2,MOD))%MOD)*count[j])%MOD;
            else
                ans += (((count[i]*count[j])%MOD)*count[k])%MOD;
        }
    }
    return ans%MOD;
}
