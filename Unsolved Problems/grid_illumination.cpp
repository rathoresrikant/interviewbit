/*
Grid Illumination
You are given an integer A. On a A x A grid of cells, each cell (x, y) with 0 <= x < A and 0 <= y < A has a lamp. Initially, some number of lamps are on. B[i] tells us the location of the i-th lamp that is on. Each lamp that is on illuminates every square on its x-axis, y-axis, and both diagonals (similar to a Queen in chess). For the i-th query C[i] = (x, y), the answer to the query is 1 if the cell (x, y) is illuminated, else 0. After each query (x, y) [in the order given by queries], we turn off any lamps that are at cell (x, y) or are adjacent 8-directionally (ie., share a corner or edge with cell (x, y).) Return an array of D. Each value D[i] should be equal to the answer of the i-th query C[i].
Input Format
The first argument given is the integer A.
The second argument given is the integer matrix B.
The third argument given is the integer matrix C.
Output Format
Return an array of integers D. Each value D[i] should be equal to the answer of the i-th query C[i]
Constraints
1 <= A <= 10^9
1 <= B.length , C.length <= 20000
B[i].length = C[i].length = 2
For Example
Input 1:
    A = 5
    B = [[0,4], [4,4]]
    C = [[1,1], [1,0]]
Output 1:
    D = [1, 0]

Input 2:
    A = 6
    B = [[1,3], [2,4], [5,4]]
    C = [[2,4], [1,2]]
Output 2:
    D = [1, 0]
*/
