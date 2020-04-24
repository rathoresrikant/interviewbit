/*
Distribute candies
Problem Description
Akash wants to distribute candies on his birthday. There are A people and he has two types of candies. B candies of the first type and C candies of the second type. He wants to distribute candies in such a way that no person has candies of both types and each person has at least one candy.
 Let X denotes the minimum candies among all people after distribution of candies.
 Find the maximum X.


Problem Constraints
2<=A<=B+C
1<=B<=10^9
1<=C<=10^9


Input Format
First argument is an integer A denoting number of people.
Second argument is an integer B denoting number of candies of first type.
Third argument is an integer C denoting number of candies of second type.


Output Format
Return an interger denoting the maximum X.


Example Input
A=4 B=4 C=5


Example Output
2


Example Explanation
We can distribute candies such that 2 persons gets candies of first type [2,2] and 2 persons gets candies of first type [3,2].
So the maximum X will be 2.
*/

bool isPossible(int a, int b, int c, int mid)
{
    return (b/mid + c/mid >= a);
}
int Solution::solve(int A, int B, int C)
{
    int left = 1, right = B + C;
    long res = 0;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(isPossible(A, B, C, mid))
        {
            res = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return res;
}
