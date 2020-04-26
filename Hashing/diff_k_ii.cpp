/*
Diffk II
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j. Example : Input :
A : [1 5 3]
k : 2
Output :
1
as 3 - 1 = 2
Return 0 / 1 for this problem.
*/
int Solution::diffPossible(const vector<int> &A, int B) {
    int n = A.size();
    if(n == 1)
        return 0;
    unordered_map <int, int> mp;
    for(int i=0; i<n; i++)
        mp[A[i]]++;
    for(int i=0; i<n; i++)
    {
        if(mp[A[i]] != 0 && mp[A[i]+B] != 0)
        {
            if(B == 0 && mp[A[i]] == 1);
            else
            return 1;

        }
    }
    return 0;
}
