/*
Find if there is a sub-array with 0 sum
Given an array of integers A, find and return whether the given array contains a subarray with a sum equal to 0. If the given array contains a sub-array with sum zero return 1 else return 0. Note: Length of sub array should be at least one.
Input Format
The only argument given is the integer array A.
Output Format
Return whether the given array contains a subarray with a sum equal to **0**.
Constraints
1 <= length of the array <= 100000
-10^9 <= A[i] <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    0

Input 2:
    A = [5, 17, -22, 11]
Output 2:
    1
*/
int Solution::solve(vector<int> &A) {
    int n = A.size(), sum = 0;
    unordered_map <long long, int> mp;
    mp[0] = 1;
    for(int i=0; i<n; i++)
    {
        sum += A[i];
        if(mp[sum] == 1)
        return 1;
        mp[sum] = 1;
    }
    return 0;
}
