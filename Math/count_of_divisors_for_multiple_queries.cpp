/*
Count of divisors for multiple queries
Problem Description
Given an array of integers A, find and return the count of divisors of each element of the array. NOTE: Order of the resultant array should be same as the input array.


Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 106


Input Format
The only argument given is the integer array A.


Output Format
Return the count of divisors of each element of the array in the form of an array.


Example Input
Input 1:
 A = [2, 3, 4, 5]
Input 2:
 A = [8, 9, 10]


Example Output
Output 1:
 [2, 2, 3, 2]
Output 1:
 [4, 3, 4]


Example Explanation
Explanation 1:
 The number of divisors of 2 : [1, 2], 3 : [1, 3], 4 : [1, 2, 4], 5 : [1, 5]
 So the count will be [2, 2, 3, 2].
Explanation 2:
 The number of divisors of 8 : [1, 2, 4, 8], 9 : [1, 3, 9], 10 : [1, 2, 5, 10]
 So the count will be [4, 3, 4].
*/
int Solution::solve(int A) {
    return sqrt(A);
}
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size(), spf[1000001], num;
    vector <int> sieve(1000001,0);
    sieve[1] = 1;
    for(int i=1; i<=1000001; i++)
        spf[i] = i;
    for(int i=2; i*i <= 1000001; i++)
    {
        if(sieve[i] == 0)
        {
            for(int j=2; i*j <= 1000001; j++)
            {
                sieve[i*j] = 1;
                if(spf[i*j] == i*j)
                    spf[i*j] = i;
            }
        }
    }
    vector <int> ans;
    for(int i=0; i <n; i++)
    {
        int count = 1;
        while(spf[A[i]] > 1) {
            int cnt = 1, u = spf[A[i]];
            while(spf[A[i]] == u) {
                cnt++;    A[i] /= u;
            }
            count *= cnt;
        }
        ans.push_back(count);
    }
    return ans;
}
