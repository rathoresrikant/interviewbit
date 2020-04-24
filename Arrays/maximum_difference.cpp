/*
Maximum Difference
Given an array of integers A and an integer B. Find and return the maximum value of | s1 - s2 | where s1 = sum of any subset of size B, s2 = sum of elements of A - sum of elemets of s1 Note |x| denotes the absolute value of x.
Input Format
The arguments given are the integer array A and integer B.
Output Format
Return the maximum value of | s1 - s2 |.
Constraints
1 <= B < length of the array <= 100000
1 <= A[i] <= 10^5
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 2
Output 1:
    9

Input 2:
    A = [5, 17, 100, 11]
    B = 3
Output 2:
    123
*/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), sum = 0, total = 0;
    for(int i=0; i<n; i++)
        total += A[i];
    sort(A.begin(), A.end());
    if(B <= n/2)
    {
        for(int i=0; i<B; i++)
            sum += A[i];
    }
    else
    {
        for(int i=n-1; i >= (n - B); i--)
            sum += A[i];
    }
    //cout << total <<" "<< sum <<endl;
    return abs(total - sum - sum);
}
