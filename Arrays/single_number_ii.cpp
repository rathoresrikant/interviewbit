/*
Single Number II
Problem Description
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

NOTE: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?



Problem Constraints
2 <= A <= 5*106
0 <= A <= INTMAX



Input Format
First and only argument of input contains an integer array A.


Output Format
Return a single integer.


Example Input
Input 1:
 A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Input 2:
 A = [0, 0, 0, 1]



Example Output
Output 1:
 4
Output 2:
 1



Example Explanation
Explanation 1:
 4 occurs exactly once in Input 1.
 1 occurs exactly once in Input 2.
 */

 int Solution::singleNumber(const vector<int> &A)
{
    int n = A.size(), ans = 0, bit, one, zero;
    for(int i=0; i<32; i++)
    {
        one = 0; zero = 0;
        for(int j=0; j<n; j++)
        {
            if(((1<<i)&A[j]) == 0)
                zero++;
            else
                one++;
        }
        if(one%3 == 0)
        bit = 0;
        else
        bit = 1;
        ans += bit*pow(2,i);
    }
    return ans;
}
