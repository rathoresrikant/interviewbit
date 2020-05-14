/*
Product of Sums
Consider a 3-tuple of integers (A,B,C) under the constraints that A<=B and C<=B. A function on the tuple is defined as:
F(A,B,C)=0 if A>B or C>B (or both).
F(A,B,C)=(A+B)*(B+C) if A<=B and C<=B.
Given 3 arrays of size P,Q,R respectively. Find the sum of all F(A,B,C) over all the 3-tuples (A,B,C) where A,B,C belong to the arrays P,Q,R respectively. Since the sum can be very large, find the sum modulo 10^9+7. Constraints:
1.   1<=P,Q,R<=100000
2.   1<= every array element <=10^9
Input: 3 integers denoting the size of the 3 arrays and 3 arrays. Output: Sum of all F(A,B,C) over all the 3-tuples (A,B,C) where A,B,C belong to the arrays P,Q,R respectively modlulo 10^9+7 Example: Input:
size of array1: 2
size of array2: 2
size of array3: 4
array1:[1 2]
array2:[4 4]
array3:[2 3 4 5]
Output:
462
*/
