/*
Find sub-array with the given sum
Problem Description
Given an array of positive integers A and an integer B, find and return first continuous subarray which adds to B. If the answer does not exist return an array with a single element "-1". First sub-array means the sub-array for which starting index in minimum.


Problem Constraints
1 <= length of the array <= 100000 1 <= A[i] <= 10^9 1 <= B <= 10^9


Input Format
The first argument given is the integer array A. The second argument given is integer B.


Output Format
Return the first continuous sub-array which adds to B and if the answer does not exist return an array with a single element "-1".


Example Input
Input 1:
A = [1, 2, 3, 4, 5]
B = 5
  Input 2:
A = [5, 10, 20, 100, 105]
B = 110



Example Output
Output 1:

[2, 3]
  Output 2:
-1



Example Explanation
Explanation 1:

[2, 3] sums up to 5.
  Explanation 2:
No subarray sums up to required number.
*/
vector<int> Solution::solve(vector<int> &A, int B) {
    long long n = A.size(), start = -1, end = -1, sum;
    vector <int> res;
    sum = A[0];
    for(int i=0, j=0; j < n;)
    {
       if(sum == B)
       {
           start = i+1;
           end = j+1;
           break;
       }
       else
       if(sum < B)
       {
           j++;
           sum += A[j];
       }
       else
       if(sum > B)
       {
           sum = sum - A[i];
           i++;
           if(i > j)
           j++;
       }
    }
    if(start == -1)
        res.push_back(-1);
    else
    {
       for(int i=start-1; i<=end-1; i++)
       res.push_back(A[i]);
    }
    return res;
}
