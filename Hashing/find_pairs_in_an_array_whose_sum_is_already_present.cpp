/*
Find pairs in array whose sum is already present
Given an array A of N distinct and positive elements, the task is to find number of unordered pairs whose sum already exists in given array. Expected Complexity : n^2 CONSTRAINTS
1 <= N <= 1000
1 <= A[i] <= 10^6 + 5
SAMPLE INPUT
A : [ 3, 4, 2, 6 ,7]
SAMPLE OUTPUT
2
EXPLANATION
The pairs following the conditions are :
(2,4) = 6,
(3,4) = 7
*/
int Solution::solve(vector<int> &A) {
    int n = A.size(), count = 0;
    unordered_set <long long> s;
    for(int i=0; i<n; i++)
        s.insert(A[i]);
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(s.find(A[i]+A[j]) != s.end())
            count++;
        }
    }
    return count;
}
