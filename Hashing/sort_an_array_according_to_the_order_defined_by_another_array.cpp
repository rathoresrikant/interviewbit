/*
Sort an array according to the order defined by another array
Given two array of integers A and B, Sort A in such a way that the relative order among the elements will be the same as those are in B. For the elements not present in B, append them at last in sorted order. Return the array A after sorting from the above method. Note: Elements of B are unique.
Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.
Output Format
Return the array A after sorting as described.
Constraints
1 <= length of the array A <= 100000
1 <= length of the array B <= 100000
-10^9 <= A[i] <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = [5, 4, 2]
Output 1:
    A = [5, 4, 2, 1, 3]

Input 2:
    A = [5, 17, 100, 11]
    B = [1, 100]
Output 2:
    [100, 5, 11, 17]
*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    int n = A.size(), m = B.size();
    unordered_map <int, int> mp;
    vector <int> res;
    sort(A.begin(), A.end());
    for(int i=0; i<n; i++)
        mp[A[i]]++;
    for(int i=0; i<m; i++)
    {
        while(mp[B[i]])
        {
            res.push_back(B[i]);
            mp[B[i]]--;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(mp[A[i]] != 0)
            res.push_back(A[i]);
    }
    return res;
}
