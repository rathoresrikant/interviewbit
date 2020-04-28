/*
Sorted Permutation Rank
Problem Description
Given a string A. Find the rank of the string amongst its permutations sorted lexicographically.
Assume that no characters are repeated. Note: The answer might not fit in an integer, so return your answer % 1000003


Problem Constraints
1 <= len(A) <= 1000


Input Format
First argument is a string A.


Output Format
Return an integer denoting the rank of the given string.


Example Input
Input 1:
A = "acb"


Example Output
Output 1:
2


Example Explanation
Explanation 1:
Given A = "acd".
The order permutations with letters 'a', 'c', and 'b' :
abc
acb
bac
bca
cab
cba
So, the rank of A is 2.
*/
int fact(int n)
{
    vector <int> fact(n+1);
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=n;i++)
    fact[i]= (i*fact[i-1])%1000003;
    return fact[n];

}

int Solution::findRank(string str) {
    int n = str.length(), sum = 1;
    string s =  str;
    vector <int> arr;
    vector <int> vec;
    map <char,int> m;
    sort(s.begin(), s.end());
    for(int i=0; i<n; i++)
        m[s[i]]= (i+1);
    for(int i=0; i<n; i++)
        arr.push_back(m[str[i]]);
    for(int i=0; i<n-1; i++)
    {
        int count = 0;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            count++;
        }
        vec.push_back(count);
    }
    vec.push_back(0);
    for(int j=0; j<n; j++)
    sum =(sum +( vec[j]*fact(n-j-1))%1000003)%1000003;
    return sum;
}
