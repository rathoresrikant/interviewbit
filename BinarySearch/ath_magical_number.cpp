/*
Ath Magical Number
Problem Description
Given three positive integers A, B and C. Any positive integer is magical if it is divisible by either B or C. Return the Ath magical number. Since the answer may be very large, return it modulo 109 + 7.


Problem Constraints
1 <= A <= 109 2 <= B, C <= 40000


Input Format
The first argument given is an integer A. The second argument given is an integer B. The third argument given is an integer C.


Output Format
Return the Ath magical number. Since the answer may be very large, return it modulo 109 + 7.


Example Input
Input 1:
 A = 1
 B = 2
 C = 3
Input 2:
 A = 4
 B = 2
 C = 3



Example Output
Output 1:
 2
Output 2:
 6



Example Explanation
Explanation 1:
 1st magical number is 2.
Explanation 2:
 First four magical numbers are 2, 3, 4, 6 so the 4th magical number is 6.
*/

int Solution::solve(int A, int B, int C)
{
    long long lcm = (B*C)/__gcd(B,C), MOD = 1e9 + 7;
    long long low = 0, high = 1e15, mid;
    while(low < high)
    {
        mid = low + (high-low)/2;
        if(mid/C + mid/B - mid/lcm < A)
            low = mid + 1;
        else
            high = mid;
    }
    return low%MOD;
}
