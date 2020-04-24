/*
Divide Integers
Divide two integers without using multiplication, division and mod operator. Return the floor of the result of the division. Example:
5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX. Note: INT_MAX = 2^31 - 1
*/

int Solution::divide(int A, int B) {
    int sign;
    long long quotient = 0, temp = 0, one = 1, a = A, b = B;
    if((a < 0 && b > 0) || (a >= 0 && b < 0))
        sign = -1;
    else
        sign = 1;
    a = abs(a);
    b = abs(b);
    for(int i=31; i>=0; i--)
    {
        if(temp + (b << i) <= a)
        {
            temp += (b << i);
            quotient |= 1LL << i;
        }
    }
    if (quotient*sign < INT_MIN || quotient*sign > INT_MAX)
        return INT_MAX;
    else
        return (quotient*sign);
}
