/*
Implement StrStr
Implement strStr().
 strstr - locate a substring ( needle ) in a string ( haystack ).
Try not to use standard library string functions for this question. Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases.
*/
int Solution::strStr(const string A, const string B) {
    int n = A.length(), m = B.length(), count;
    if(m == 0)
        return -1;
    for(int i=0; i<n; i++)
    {
        if(A[i] == B[0])
        {
            count = 1;
            for(int j=1; j<m; j++)
            {
                if(A[i+j] == B[j])
                    count++;
            }
            if(count == m)
                return i;
        }
    }
    return -1;
}
