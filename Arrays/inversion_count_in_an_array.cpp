/*
Inversion count in an array
Given an array of integers A. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Find the total number of inversions of A modulo (10^9 + 7).
Input Format
The only argument given is the integer array A.
Output Format
Return the number of inversions of A modulo (10^9 + 7).
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9
For Example
Input 1:
    A = [1, 2, 5, 4, 3]
Output 1:
    3

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    1
*/

long long inv_count = 0;

void count_inversions(vector <int> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for(i=0; i<n1; i++)
        L[i] = arr[l+i];
    for(j=0; j<n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            inv_count += (n1 - i);
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector <int> &arr, int l, int r)
{
    if(l < r)
    {
        int mid = (l + r)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        count_inversions(arr, l, mid, r);
    }
}
int Solution::solve(vector<int> &A) {
    long long MOD = 1e9+7;
    int n = A.size();
    inv_count = 0;
    mergesort(A, 0, n-1);
    return inv_count%MOD;
}
