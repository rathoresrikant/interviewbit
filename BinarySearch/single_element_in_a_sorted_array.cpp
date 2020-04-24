/*
Single Element in a Sorted Array
Given a sorted array of integers A where every element appears twice except for one element which appears once, find and return this single element that appears only once.
Input Format
The only argument given is the integer array A.
Output Format
Return the single element that appears only once.
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9
For Example
Input 1:
    A = [1, 1, 2, 2, 3]
Output 1:
    3

Input 2:
    A = [5, 11, 11, 100, 100]
Output 2:
    5
*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int left = 0, right = n-1, mid;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(A[mid] != A[mid + 1] && A[mid] != A[mid - 1])
            return A[mid];

        if(A[mid] == A[mid + 1]) //first occurence
        {
            if(mid%2 == 1)
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if(mid%2 == 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
}
