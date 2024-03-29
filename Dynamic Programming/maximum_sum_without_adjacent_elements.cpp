/*
Max Sum Without Adjacent Elements
Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it. Note: You can choose more than 2 numbers. Input Format:
The first and the only argument of input contains a 2d matrix, A.
Output Format:
Return an integer, representing the maximum possible sum.
Constraints:
1 <= N <= 20000
1 <= A[i] <= 2000
Example:
Input 1:
    A = [   [1]
            [2]    ]

Output 1:
    2

Explanation 1:
    We will choose 2.

Input 2:
    A = [   [1, 2, 3, 4]
            [2, 3, 4, 5]    ]

Output 2:
    We will choose 3 and 5.
*/

int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    int incl = max(A[0][0], A[1][0]), excl = 0, excl_new;
    for(int i=1; i<n; i++)
    {
        excl_new = max(incl, excl);
        incl = max(A[0][i], A[1][i]) + excl;
        excl = excl_new;
    }
    return max(incl, excl);
}
