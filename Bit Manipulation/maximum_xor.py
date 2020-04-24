'''
Maximum XOR
Problem Description
Given an array of integers A, find and return the maximum result of A[i] XOR A[j], where i, j are the indexes of the array.


Problem Constraints
1 <= length of the array <= 100000
0 <= A[i] <= 109


Input Format
The only argument given is the integer array A.


Output Format
Return an integer denoting the maximum result of A[i] XOR A[j].


Example Input
Input 1:
 A = [1, 2, 3, 4, 5]
Input 2:
 A = [5, 17, 100, 11]



Example Output
Output 1:
 7
Output 2:
 117



Example Explanation
Explanation 1:
 Maximum XOR occurs between element of indicies(0-based) 1 and 4 i.e. 2 ^ 5 = 7.
Explanation 2:
 Maximum XOR occurs between element of indicies(0-based) 1 and 2 i.e. 17 ^ 100 = 117.
'''

 class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        answer = 0
        for i in range(32)[::-1]:
            answer <<= 1
            prefixes = {num >> i for num in A}
            answer += any(answer^1 ^ p in prefixes for p in prefixes)
        return answer
