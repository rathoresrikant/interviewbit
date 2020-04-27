/*
Longest Subarray Sum B
Given an array of integers A of size N and an integer B. Find the length of longest subarray having sum equal to B. If no such subarray exists then return -1.
Input Format
The First argument given is the integer array A.
The Second argument is an integer B.
Output Format
Return the length of longest subarray having sum equal to B if exists else return -1.
Constraints
1 <= N <= 100000
-10^6 <= A[i] <= 10^6
-10^9 <= B <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 10

Output 1:
    4

Input 2:
    A = [1, -1, -1, 1]
    B = 0
Output 2:
    4
*/
int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), sum = 0, ans = -1, res  = -1;
    unordered_map <long long, int> mp;
    mp[0] = 1;
    for(int i=0; i<n; i++)
    {
        sum += A[i];
        if(mp[sum] == 0)
            mp[sum] = i+2;
        if(mp[sum-B] != 0)
            ans = (i+2 - mp[sum-B]);
        res = max(ans, res);
    }
    return res;
}
