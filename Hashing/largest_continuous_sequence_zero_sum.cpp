/*
Largest Continuous Sequence Zero Sum
Problem Description
Given an array A of N integers. Find the largest continuous sequence in a array which sums to zero.


Problem Constraints
1 <= N <= 106 -107 <= A[i] <= 107


Input Format
Single argument which is an integer array A.


Output Format
Return an array denoting the longest continuous sequence with total sum of zero. NOTE : If there are multiple correct answers, return the sequence which occurs first in the array.


Example Input
A = [1,2,-2,4,-4]


Example Output
[2,-2,4,-4]


Example Explanation
[2,-2,4,-4] is the longest sequence with total sum of zero.
*/
vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size(), sum = 0, ans, res = 0, start = -1, end = -1;
    unordered_map <long long, int> mp;
    mp[0] = 1;
    for(int i=0; i<n; i++)
    {
        sum += A[i];
        if(mp[sum] != 0)
        {
            ans = (i+2) - mp[sum];
            if(ans > res)
            {
                start = mp[sum]-1;
                end = i;
                res = ans;
            }
        }
        else
        mp[sum] = i + 2;
    }
    vector <int> temp;
    if(start != -1)
    {
        for(int i=start; i<=end; i++)
            temp.push_back(A[i]);
        return temp;
    }
}
