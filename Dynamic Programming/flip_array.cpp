/*
Flip Array
Given an array of positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible). Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative. Constraints:
 1 <= n <= 100
Sum of all the elements will not exceed 10,000. Example:
A = [15, 10, 6]
ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )
A = [14, 10, 4]
ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)
 Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there are not minimum
*/

int Solution::solve(const vector<int> &A)
{
    int n = A.size();
    long long sum = 0;
    for(int i=0; i<n; i++)
        sum += A[i];
    vector <vector <long long> > dp((n+1), vector <long long>(sum+1));
    for(int i=0; i<=n; i++)
        for(int j=0; j<=sum; j++)
            dp[i][j] = INT_MAX;
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=A[i-1]; j<=sum; j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-A[i-1]] + 1);
        }
    }
    for(int j=sum/2; j>=0; j--)
        if(dp[n][j] != INT_MAX)
            return dp[n][j];
}
