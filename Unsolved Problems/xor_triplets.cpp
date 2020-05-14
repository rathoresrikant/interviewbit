/*
XOR TRIPLETS
Problem Description
Given an array of integers A of size N. A triplet (i, j, k), i <= j <= k is called a power triplet if A[i] ^ A[i+1] ^....A[j-1] = A[j] ^.....^A[k]. Where, ^ denotes bitwise xor. Return the count of all possible power triplets. Since the answer could be large return answer % 109 +7.


Problem Constraints
1 <= N <= 100000
1 <= A[i] <= 100000


Input Format
The first argument given is the integer array A.


Output Format
Return the count of all possible power triplets % 109 + 7.


Example Input
Input 1:
 A = [5, 2, 7]
Input 2:
 A = [1, 2, 3]



Example Output
Output 1:
 2
Output 2:
 2



Example Explanation
Explanation 1:
 All possible power triplets are:
    1. (1, 2, 3) ->  A[1] = A[2] ^ A[3]
    2. (1, 3, 3) ->  A[1] ^ A[2] = A[3]
Explanation 2:
 All possible power triplets are:
    1. (1, 2, 3) ->  A[1] = A[2] ^ A[3]
    2. (1, 3, 3) ->  A[1] ^ A[2] = A[3]
*/
