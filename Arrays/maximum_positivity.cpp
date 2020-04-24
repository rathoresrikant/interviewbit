/*
Maximum positivity
Problem Description
Given an array of integers A of size N. Return maximum size subarray of A having only non-negative elements. If there are more than one such subarrays, return the one having earliest starting index in A.


Problem Constraints
1 <= N <= 105 -109 <= A[i] <= 109


Input Format
The first and only argument given is the integer array A.


Output Format
Return maximum size subarray of A having only non-negative elements. If there are more than one such subarrays, return the one having earliest starting index in A.


Example Input
Input 1:
 A = [5, 6, -1, 7, 8]
  Input 2:
 A = [1, 2, 3, 4, 5, 6]



Example Output
Output 1:
 [5, 6]
  Output 2:
 A = [1, 2, 3, 4, 5, 6]



Example Explanation
Explanation 1:
 There are two subarrays of size 2 having only non-negative elements.
 1. [5, 6]  starting point  = 0
 2. [7, 8]  starting point  = 3
 As starting point of 1 is smaller, return [5, 6]
  Explanation 2:
 There is only one subarray of size 6 having only non-negative elements:
 [1, 2, 3, 4, 5, 6]
 */

 vector<int> Solution::solve(vector<int> &A)
{
    int n = A.size();
    vector <int> ans;
    int start, end, res = 0;
    for(int i=0, j=0; i<n && j<n;)
    {
        if(A[j] >= 0)
        {
            j++;
        }
        else
        {
            i = j + 1;
            j = j + 1;
        }
        if(j-i+1 > res)
        {
            start = i;
            end = j-1;
            res = (j-i+1);
        }
    }
    for(int i=start; i<=end; i++)
    {
        ans.push_back(A[i]);
    }
    return ans;
}
