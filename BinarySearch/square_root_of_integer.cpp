/*
Square Root of Integer
Problem Description
Given an integer A. Compute and return the square root of A. If A is not a perfect square, return floor(sqrt(A)). DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY.


Problem Constraints
0 <= A <= 1010


Input Format
The first and only argument given is the integer A.


Output Format
Return floor(sqrt(A))


Example Input
Input 1:
 11
Input 2:
 9



Example Output
Output 1:
 3
Output 2:
 3



Example Explanation
Explanation:
 When A = 11 , square root of A = 3.316. It is not a perfect square so we return the floor which is 3.
 When A = 9 which is a perfect square of 3, so we return 3.
*/

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long low = 0, high = A, mid, temp;
    while(low < high)
    {
        mid = (low + high + 1)/2;
        temp = mid*mid;
        if(temp == A)
            return mid;
        else
        if(temp < A)
            low = mid;
        else
        if(temp > A)
            high = mid - 1;
    }
    return low;
}
