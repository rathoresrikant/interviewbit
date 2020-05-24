/*
Maximize power
Problem Description
Given an array of integers of size N. Special subarray is a subarray whose length is a power of 2. Power of a special subarray is the maximum element in that subarray. Divide the array into special subarrays such that power of the array is maximum.
Power of an array is defined as sum of power of all special subarrays in which the array is divided. Note: Answer will fit in 32 bit integer.


Problem Constraints
1 <= N <= 100000
-100000 <= A[i] <= 100000


Input Format
First argument is an integer array A of size N


Output Format
Return an integer denoting the maximum power of the given array.


Example Input
Input 1:
 A = [4, 16, -11]
Input 2:
 A = [2, 3, 5, 1]



Example Output
Output 1:
 20
Output 1:
 11



Example Explanation
Explanation 1:
 We can divide the array into two special subarrays [4] and [16, -11] with power 4 and 16 repectively.
Explanation 2:
 As subarray of length 1(20 = 1) is also a special subarray, We can take all elements of the array.
 Divide the given array into 4 special subarrays [2], [3], [5] and [1] with power 2, 3, 5, and 1 repectively.
 */

 
