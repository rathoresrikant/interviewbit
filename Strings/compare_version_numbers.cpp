/*
Compare Version Numbers
Compare two version numbers version1 and version2.
If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character. The . character does not represent a decimal point and is used to separate number sequences. For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision. Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 1.13 < 1.13.4
*/
int Solution::compareVersion(string A, string B) {
    int n1 = A.length(), n2 = B.length();
    unsigned long long i = 0,  j = 0, res1  = 0, res2 = 0, dots1 = 0, dots2 = 0;
    while(i < n1 || j < n2)
    {
        while(i < n1 && A[i] != '.')
        {
            res1 =  res1*10 + (A[i]-'0');
            i++;
        }
        while(j < n2 && B[j] != '.')
        {
            res2 = res2*10 + (B[j]-'0');
            j++;
        }
        if(res1 > res2)
            return 1;
        else
        if(res2 > res1)
            return -1;
        res1 = 0, res2 = 0;
        if(i < n1)
        {
            i++;
            dots1++;
        }
        if(j < n2)
        {
            j++;
            dots2++;
        }
    }
    return 0;
}
