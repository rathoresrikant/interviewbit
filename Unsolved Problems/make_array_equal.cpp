/*
Make array equal
Problem Description
Given two array A and B both of size N consisting of distinct integers. You have to make array A equal to B.
In one move, you can:
choose any element of the array A and change its value to any integer.
do the cyclic right rotation of the array A.

Find the minimum number of moves required to make array A equal to B.


Problem Constraints
1 <= N <= 100000
1 <= A[i], B[i] <= 109


Input Format
First argument is an integer array A.
Second argument is an integer array B.


Output Format
Return an integer output denoting the minimum number of moves.


Example Input
Input 1:
 A = [2, 3, 5, 1, 7]
 B = [7, 2, 10, 6, 1]

 Input 2:
 A = [1, 2, 3]
 B = [4, 5, 2]




Example Output
Output 1:
 3
 Output 2:
 3



Example Explanation
Explanation 1:
 In one move we will do cyclic right rotation so the array becomes, A = [7, 2, 3, 5, 1].
 Now in other two moves we can change A[2] from 3 to 10 and A[3] from 5 to 6.
 So the minimum number of moves will be 3.
 Explanation 2:
 In all three moves, we will change the integers at their respective indices.
 */

 
