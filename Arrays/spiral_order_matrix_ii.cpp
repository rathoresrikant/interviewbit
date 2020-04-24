/*
Spiral Order Matrix II
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.
 Input Format:
The first and the only argument contains an integer, A.
Output Format:
Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:
1 <= A <= 1000
Examples:
Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
*/

vector<vector<int> > Solution::generateMatrix(int A)
{
    vector <vector <int> > arr(A, vector <int> (A));
    int top = 0, bottom = A-1, left = 0, right = A-1, count  = 1, dir = 1;
    while(count <= A*A)
    {
        if(dir == 1)
        {
            for(int i=left; i<=right; i++)
                arr[top][i] = count++;
            top++;
            dir = 2;
        }
        else
        if(dir ==  2)
        {
            for(int i = top; i<= bottom; i++)
                arr[i][right] = count++;
            right--;
            dir = 3;
        }
        else
        if(dir == 3)
        {
            for(int i=right; i >= left; i--)
                arr[bottom][i] = count++;
            bottom--;
            dir = 4;
        }
        else
        if(dir == 4)
        {
            for(int i=bottom; i>=top; i--)
                arr[i][left] = count++;
            left++;
            dir = 1;
        }
    }
    return arr;
}
