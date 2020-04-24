/*
Move all zeroes to end of the array
Given an array of integers A, push all the zeroes in the array to the end of the array keeping the order of all the remaining elements same. More formally, if A[i] and A[j] are two non zero elements and A[i] is in the left A[j] in the original array then A[i] will be in the left of A[j] in the final answer as well. Note: Modify the array in place, no extra memory allowed.
Input Format
The only argument given is the integer array A.
Output Format
Return the modified array.
Constraints
1 <= length of the array <= 100000
-10^9 <= A[i] <= 10^9
For Example
Input 1:
    A = [1, 0, 3, 5, 0]
Output 1:
    [1, 3, 5, 0, 0]

Input 2:
    A = [5, 17, 0, 11]
Output 2:
    [5, 17, 11, 0]
*/

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size(), j;
	for(int i=0, j=0; i<n; i++)
	{
	    if(A[i] == 0)
	    {
	        if(j < i)
	            j = i;
	        while(A[j] == 0 && j < n-1 )
	            j++;
	        swap(A[i], A[j]);
	    }
	}
	return A;
}
