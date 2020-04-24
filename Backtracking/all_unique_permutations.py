'''
All Unique Permutations
Problem Description
Given an array A of size N denoting collection of numbers that might contain duplicates, return all possible unique permutations. NOTE: No 2 entries in the permutation sequence should be the same.
WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.


Problem Constraints
1 <= N <= 9


Input Format
Only argument is an integer array A of size N.


Output Format
Return a 2-D array denoting all possible unique permutation of the array.


Example Input
A = [1, 1, 2]


Example Output
[ [1,1,2]
  [1,2,1]
  [2,1,1] ]


Example Explanation
All the possible unique permutation of array [1, 1, 2].
'''

class Solution:
    # @param A : list of integers
    # @return a list of list of integers
    def permute(self, A):
        if len(A) == 0:
            return [[]]
        A = sorted(A)
        ans = []
        n = len(A)
        for i in range(1, n):
            if A[i] == A[i - 1]:
                continue
            else:
                for l in self.permute(A[0:i - 1] + A[i:]):
                    ans.append([A[i - 1]] + l)

        for l in self.permute(A[0:len(A) - 1]):
            ans.append([A[len(A) - 1]] + l)

        return ans
