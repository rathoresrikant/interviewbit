/*
Longest Consecutive Sequence
Problem Description
Given an unsorted integer array A of size N. Find the length of the longest set of consecutive elements from the array A.


Problem Constraints
1 <= N <= 106 -106 <= A[i] <= 106


Input Format
First argument is an integer array A of size N.


Output Format
Return an integer denoting the length of the longest set of consecutive elements from the array A.


Example Input
 A = [100, 4, 200, 1, 3, 2]


Example Output
 4


Example Explanation
 The set of consecutive elements will be [1, 2, 3, 4].
*/
int Solution::longestConsecutive(const vector<int> &A) {
    int n = A.size(), minm, maxm;
    unordered_map <long long, int> mp;
    minm = *min_element(A.begin(), A.end()), maxm = *max_element(A.begin(), A.end());
    for(int i=0; i<n; i++)
        mp[A[i]]++;
    int streak = 0, maxstreak = 0;
    for(int i=minm; i<=maxm; i++)
    {
        if(mp[i] != 0)
        {
            streak++;
            if(streak > maxstreak)
                maxstreak = streak;
        }
        else
        streak = 0;
    }
    if(maxstreak == 0)
    return 1;
    else
    return maxstreak;
}
