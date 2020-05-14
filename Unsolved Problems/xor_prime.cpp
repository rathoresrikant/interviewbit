/*
XOR Prime
Problem Description
Given an array A of integers of size N. For each integer in A, there is a set S of the prime factors of that integer. There is a good value associated with each number, which is the sum of XOR of all subsets of set S modulo 109+7.  Good Value of the array A is the sum of good values associated with each number modulo 109+7. Return Good Value of A.  Note: Set S has no duplicates.


Problem Constraints
1 <= N <= 1000 1 <= A[i] <= 109


Input Format
Single argument is an integer.


Output Format
Return the Good Value of A.


Example Input
Input 1:
 A = [10, 45]
 Input 2:
 A = [3, 7]



Example Output
Output 1:
 28
 Output 2:
 10



Example Explanation
Explanation 1:
Prime factors of 10 are 2, 5. Subsets of {2,5} are {},{2},{5},{2,5}. Their corresponding xors are 0,2,5,7.
Their sum is 0+2+5+7 = 14.  So, good value of 10 is 14.
Prime factors of 45 are 3, 5. Subsets of {3,5} are {},{3},{5},{3,5}. Their corresponding xors are 0,3,5,6.
Their sum is 0+3+5+6 = 14.  So, good value of 45 is 14.

Good Value of array = 14 + 14 = 28.
*/
