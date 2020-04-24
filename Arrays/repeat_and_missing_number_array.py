'''
Repeat and Missing Number Array
You are given a read only array of n integers from 1 to n. Each integer appears exactly once except A which appears twice and B which is missing. Return A and B. Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? Note that in your output A should precede B. Example:
Input:[3 1 2 5 3]

Output:[3, 4]

A = 3, B = 4
'''

class Solution:
    # @param A : tuple of integers
    # @return a list of integers
    def repeatedNumber(self, A):
        n = len(A)
        sum = 0
        total= 0
        sqsum = 0
        ssum = 0
        for i in range (0,n):
            total = (total + A[i])
            sum = (sum + (i+1))
            sqsum = (sqsum + A[i]*A[i])
            ssum =  (ssum + (i+1)*(i+1))
        diff = total - sum
        diffsq = sqsum - ssum
        aplusb = diffsq/diff
        a = (aplusb + diff)/2
        b = (aplusb - a)
        a = int(a)
        b = int(b)
        ans = [a,b]
        return ans
