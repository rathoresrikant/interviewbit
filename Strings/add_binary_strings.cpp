/*
Add Binary Strings
Given two binary strings, return their sum (also a binary string). Example:
a = "100"

b = "11"
Return a + b = "111".
*/
string Solution::addBinary(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int n = A.length(), m = B.length(), a, b, diff;
    if(n > m)
    {
        diff = n - m;
        while(diff--)
        {
            B.push_back('0');
            m++;
        }
    }
    if(m > n)
    {
        diff = m - n;
        while(diff--)
        {
            A.push_back('0');
            n++;
        }
    }
    int carry = 0;
    string res;
    for(int i=0; i<n; i++)
    {
        a = A[i] - '0', b = B[i] - '0';
        if(a + b + carry == 0)
        {
            res.push_back('0');
            carry = 0;
        }
        else
        if(a + b + carry == 1)
        {
            res.push_back('1');
            carry = 0;
        }
        if(a + b + carry == 2)
        {
            res.push_back('0');
            carry = 1;
        }
        else
        if(a + b + carry == 3)
        {
            res.push_back('1');
            carry = 1;
        }
    }
    if(carry == 1)
        res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}
