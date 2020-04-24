/*
N/3 Repeat Number
You're given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space. If so, return the integer. If not, return -1. If there are multiple solutions, return any one. Example :
Input : [1 2 3 1 1]
Output : 1
1 occurs 3 times which is more than 5/3 times.
*/

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size(), first = INT_MAX, second = INT_MAX, c1 = 0, c2 = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] == first)
        {
            c1++;
        }
        else
        if(A[i] == second)
        {
            c2++;
        }
        else
        if(c1 == 0)
        {
            first = A[i];
            c1++;
        }
        else
        if(c2 == 0)
        {
            second = A[i];
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1 = 0, c2 = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] == first)
            c1++;
        else
        if(A[i] == second)
            c2++;
    }
    if(c1 > n/3)
        return first;
    else
    if(c2 > n/3)
        return second;
    else
        return -1;
}
