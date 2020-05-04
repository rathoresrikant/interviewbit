/*
Sum of minimum and maximum elements of all subarrays of size k
Given an array A of both positive and negative integers. Your task is to compute sum of minimum and maximum elements of all sub-array of size B. Note: Since the answer can be very large, you are required to return the sum module 1000000007.
Input Format
The first argument denotes the array A.
The second argument denotes the value B
Output Format
Return an integer that denotes the required value.
Constraints
1 <= size of array A <= 100000
-1000000000 <= A[i] <= 1000000000
1 <= B <= size of array
** Example**
Example Input 1:
    A[] = {2, 5, -1, 7, -3, -1, -2}
    B = 4

Example Output 1:
    18
Explanation :
    Subarrays of size 4 are :
        {2, 5, -1, 7},   min + max = -1 + 7 = 6
        {5, -1, 7, -3},  min + max = -3 + 7 = 4
        {-1, 7, -3, -1}, min + max = -3 + 7 = 4
        {7, -3, -1, -2}, min + max = -3 + 7 = 4
        Sum of all min & max = 6 + 4 + 4 + 4
                             = 18
*/


int Solution::solve(vector<int> &A, int B) {
   int n = A.size();
   deque <int> q1, q2;
   long long i, sum = 0, MOD = 1e9 + 7;
   for(i = 0; i < B; i++)
   {
        while(!q1.empty() && A[q1.back()] >= A[i])
            q1.pop_back();
        while(!q2.empty() && A[q2.back()] <= A[i])
            q2.pop_back();
        q1.push_back(i);
        q2.push_back(i);
   }
   for(; i<n; i++)
   {
        sum += (A[q1.front()] + A[q2.front()] + MOD)%MOD;
        while(!q1.empty() && q1.front() <= i - B)
            q1.pop_front();
        while(!q2.empty() && q2.front() <= i - B)
            q2.pop_front();
        while(!q1.empty() && A[q1.back()] >= A[i])
            q1.pop_back();
        while(!q2.empty() && A[q2.back()] <= A[i])
            q2.pop_back();
        q1.push_back(i);
        q2.push_back(i);
   }
   sum += (A[q1.front()] + A[q2.front()] + MOD)%MOD;
   return (sum)%MOD;
}
