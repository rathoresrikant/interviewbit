/*
Multiple left rotations of the array
Given an array of integers A and multiple values in B which represents the indices of the array A around which left rotation of the array A needs to be performed. Find the rotated array for each value and return the result in the from of a matrix where i'th row represents the rotated array for the i'th value in B.
Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.
Output Format
Return the resultant matrix.
Constraints
1 <= length of both arrays <= 2000
-10^9 <= A[i] <= 10^9
0 <= B[i] <= 2000
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = [2, 3]
Output 1:
    [ [3, 4, 5, 1, 2]
      [4, 5, 1, 2, 3] ]

Input 2:
    A = [5, 17, 100, 11]
    B = [1]
Output 2:
    [ [17, 100, 11, 5] ]
*/

vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    int rows = B.size(), cols = A.size();
    vector <int> arr;
    for(int i=0; i<rows; i++)
    {
        if(B[i] < cols)
            arr.push_back(B[i]);
        else
            arr.push_back(B[i]%cols);
    }
    rows = arr.size();
    vector <vector <int> > res(rows, vector <int> (cols));
    for(int i=0; i<rows; i++)
    {
        int idx = arr[i];
        int k = 0;
        for(int j=idx; j<cols; j++)
        {
            res[i][k] = A[j];
            k++;
        }
        for(int j=0; j<idx; j++)
        {
            res[i][k] = A[j];
            k++;
        }
    }
    return res;
}
