/*
Minimize the absolute difference
Given three sorted arrays A, B and Cof not necessarily same sizes. Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively. i.e. minimize | max(a,b,c) - min(a,b,c) |. Example : Input:
A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:
1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
*/
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int p = A.size(), q = B.size(), r = C.size(), res = INT_MAX, maxm, minm;
    for(int i=0, j=0, k=0; i<p && j <q && k<r;)
    {
        int a = A[i], b = B[j], c = C[k];
        minm = min(a,min(b,c));
        maxm = max(a,max(b,c));
        res = min(abs(maxm-minm),res);
        if(minm == a)
        i++;
        else
        if(minm == b)
        j++;
        else
        if(minm == c)
        k++;
    }
    return res;
}
