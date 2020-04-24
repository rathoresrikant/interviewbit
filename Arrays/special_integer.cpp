/*
Special Integer
Given an array of integers A and an integer B, find and return the maximum value K such that there is no subarray in A of size K with sum of elements greater than B.
Input Format
The first argument given is the integer array A.
The second argument given is integer B.
Output Format
Return the maximum value of K (sub array length).
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9
1 <= B <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 10
Output 1:
    2

Input 2:
    A = [5, 17, 100, 11]
    B = 130
Output 2:
    3
*/
int Solution::solve(vector<int> &A, int B) {
    long long  n = A.size(), sum = 0, res = INT_MAX, low, high, mid, flag = 0;
    vector <long long> arr(n);
    arr[0] = A[0];
    for(int i=1; i<n; i++)
        arr[i] = (long long)(arr[i-1] + A[i]);
    if(arr[n-1] <= B)
        return n;
    for(int i=0; i<n; i++)
    {
        if(i == 0)
        sum = 0;
        else
        sum = arr[i-1];
        low = i, high = n-1, flag = 0;
        while(low < high)
        {
            mid = (low + high + 1)/2;
            if(arr[mid]-sum > B)
            {
            high = mid -1;
            flag = 1;
            }
            else
            low = mid;
        }
        if(flag == 1)
        res = min(res,(high - i + 1));
    }
    return res;
}
