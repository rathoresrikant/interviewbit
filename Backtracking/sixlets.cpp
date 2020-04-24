/*
SIXLETS
Problem Description
Given a array of integers A of size N and an integer B. Return number of non-empty subsequences of A of size B having sum <= 1000.


Problem Constraints
1 <= N <= 20 1 <= A[i] <= 1000 1 <= B <= N


Input Format
The first argument given is the integer array A. The second argument given is the integer B.


Output Format
Return number of subsequences of A of size B having sum <= 1000.


Example Input
Input 1:
    A = [1, 2, 8]
    B = 2
Input 2:
    A = [5, 17, 1000, 11]
    B = 4


Example Output
Output 1:
3
Output 2:
0


Example Explanation
Explanation 1:
 {1, 2}, {1, 8}, {2, 8}

*/
int fun(vector <int> &arr, int sum, int i, int B, int elements)
{
    if(elements == B)
    {
        if(sum <= 1000)
            return 1;
        else
            return 0;
    }
    if(i == arr.size())
        return 0;
    int p1 = fun(arr, sum+arr[i], i+1, B, elements+1);
    int p2 = fun(arr, sum, i+1, B, elements);
    return p1 + p2;
}
int Solution::solve(vector<int> &A, int B)
{
    int res = fun(A, 0, 0, B, 0);
    return res;
}
