/*
Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times. You may assume that the array is non-empty and the majority element always exist in the array. Example :
Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2.
*/
int Solution::majorityElement(const vector<int> &A)
{
    int n = A.size(), idx = 0, count = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] == A[idx])
            count++;
        else
            count--;
        if(count == 0)
        {
            idx = i;
            count = 1;
        }
    }
    count = 0;
    for(int i=0; i<n; i++)
        if(A[i] == A[idx])
            count++;
    if(count > n/2)
        return A[idx];
    else
        return -1;
}
