/*
Maximum Product Increasing Subsequence
Problem Description
Given an array of integers A of size N. Your task is to find maximum product of increasing subsequence of size 3 i.e. you need to find maximum value of A[i] * A[j] * A[k] such that A[i] < A[j] < A[k] and i < j < k < N for all increasing subsequences of size 3. If there is no increasing subsequence of size 3 return -1, else return maximum product of increasing subsequence of size 3 modulo 109+7. NOTE: All elements of the array A are distinct.


Problem Constraints
1 <= N <= 105 1 <= A[i] <= 106


Input Format
The only argument given is the integer array A.


Output Format
If there is no increasing subsequence of size 3 return -1, else return maximum product of increasing subsequence of size 3 modulo 109+7.


Example Input
Input 1:
 A = [10, 11, 9, 5, 6, 1, 20]
Input 2:
 A = [5, 4, 3, 2, 1]


Example Output
Output 1:
 2200
Output 2:
 -1


Example Explanation
Explanation 1:
 Maximum product is achieved when i=0, j=1, k=6 i.e A[0] * A[1] * A[6] = 10 * 11 * 20 = 2200.
Explanation 2:
 There is no increasing subsequence of size 3.
*/

string Solution::solve(string A, int B) {
    int n = A.length();
    vector <int> mp(26,0);
    for(int i=0; i<n; i++)
        mp[A[i]-'a']++;
    for(int i=0; i<n; i++)
    {
        if(mp[A[i]]%2 == 0)
        {
            A[i] = 'a' + (A[i] + B - 'a')%26;
        }
        else
        {
            A[i] = 'a' + (A[i] - B%26 - 'a' + 26)%26;
        }
    }
    return A;
}
int Solution::solve(vector<int> &A)
{
    int n = A.size();
    unsigned long long MOD = 1e9+7;
    vector <long long> left(n,0), right(n,0);
    set <long long> s;
    for(int i=0; i<n; i++)
    {
        auto m = s.insert(A[i]);
        auto idx = m.first;
        --idx;
        if(idx != s.end())
            left[i] = *idx;
        else
            left[i] = -1;
    }
    long long res = -1;
	int maxm = A[n-1];
	for (int i=n-2 ; i >= 1; i--)
	{
		if (A[i] > maxm)
			maxm = A[i];
		else if (left[i] != -1)
		{
		    long long temp = left[i]*A[i]*maxm;
			res = max(res, temp);
		}
	}
	if(res == -1)
	    return -1;
	else
        return res%MOD;
}
