/*
Weird Queries
Problem Description
You are given an integer array A of size N.
Process Q queries of form L R X Y, meaning for all i in [L, R] set A[i] = (X * A[i] + Y) % 1000000009.

Return the final array after processing all the queries



Problem Constraints
1 <= L <= R <= N <= 50000
1 <= Q <= 50000
0 <= A[i],X,Y <= 10^9



Input Format
First argument of input contains a single integer array A
Second argument of input contains a Q x 4 integer matrix where each row denote a query


Output Format
Return the final integer array after processing all queries.


Example Input
Input 1:
A = [1, 2, 3, 4], B = [[1, 3, 2, 1], [4, 4, 2, 2]]

Input 2:
A = [7, 2, 3], B = [[1, 2, 0, 1], [2, 3, 1, 0]]



Example Output
Output 1:
[3, 5, 7, 10]

Output 2:
[1, 1, 3]



Example Explanation
Explanation 1:
Initially, A = [1, 2, 3, 4]
After Query [1, 3, 2, 1], A = [3, 5, 7, 1]
After Query [4, 4, 2, 2], A = [3, 5, 7, 10]
*/
