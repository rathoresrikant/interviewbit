/*
Falling Squares
On an infinite number line (x-axis), we drop given squares in the order they are given. The i-th square dropped (A[i] = (left, side_length)) is a square with the left-most point being A[i][0] and side length A[i][1]. The square is dropped with the bottom edge parallel to the number line, and from a higher height than all currently landed squares. We wait for each square to stick before dropping the next. The squares are infinitely sticky on their bottom edge, and will remain fixed to any positive length surface they touch (either the number line or another square). Squares dropped adjacent to each other will not stick together prematurely. Given A, find and return a list of heights H. Each height H[i] represents the current highest height of any square we have dropped, after dropping squares represented by A[0], A[1], ..., A[i].
Input Format
The only argument given is the integer matrix A.
Output Format
Return the array H.
Constraints
1 <= length of the array A <= 1000
1 <= A[i][0] <= 10^8
1 <= A[i][1] <= 10^6
For Example
Input 1:
    A = [[1, 2], [2, 3], [6, 1]]
Output 1:
    [2, 5, 5]

Input 2:
    A = [[100, 100], [200, 100]]
Output 2:
    [100, 100]
*/
