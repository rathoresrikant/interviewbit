/*
Equal
Problem Description
Given an array A of N integers, find the index of values that satisfy P + Q = R + s, where P,Q,R & S are integers values in the array
NOTE:

1) Return the indices `A1 B1 C1 D1`, so that
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1

2) If there are more than one solutions,
   then return the tuple of values which are lexicographical smallest.

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices in the array )
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 if:
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2



Problem Constraints
1 <= N <= 1000 0 <= A[i] <= 1000


Input Format
Single argument which is an integer array A of size N.


Output Format
Return an array of size 4 which indexes of values P,Q,R and S.


Example Input
A= [3, 4, 7, 1, 2, 9, 8]


Example Output
[0, 2, 3, 5]

 Note: indexes returned should be 0-based.


Example Explanation
A[0] + A[2] = A[3] + A[5]

*/
