/*
Parity Queries
Given an empty multiset of integers initially and N queries to perform on it. + X — add non-negative integer X to the multiset. Note, that there may be many occurrences of the same integer. - X — delete a single occurrence of non-negative integer X from the multiset. It's guaranteed, that there is at least one X in the multiset. ? S — count the number of integers in the multiset (with repetitions) that match some pattern S consisting of 0 and 1. In the pattern, 0 stands for the even digits, while 1 stands for the odd. Integer X matches the pattern S, if the parity of the i'th from the right digit in decimal notation matches the i'th from the right digit of the pattern. If the pattern is shorter than this integer, it's supplemented with 0's from the left. Similarly, if the integer is shorter than the pattern its decimal notation is supplemented with the 0's from the left. For example, if the pattern is S = 010, than integers 92, 2212, 50 and 414 match the pattern, while integers 3, 110, 25 and 1030 do not. Given an array of characters A and an array of Strings B (representing the value of X for each query) of size N each, perform the queries and return the result for every third query in the form of an array of integers.
Input Format
The first argument given is the character array A.
The second argument given is the String array B.
Output Format
Return the answer for every third query in the form of an array of integers.
Constraints
1 <= N <= 100000
A[i] = {'+', '-', '?'}
0 <= B[i] <= 10^18  (given in the form of string)
For Example
Input 1:
    A = ['+', '+', '-', '?']
    B = [200, 200, 200, 0]
Output 1:
    [1]

Input 2:
    A = ['+', '+', '?', '+', '-', '?']
    B = [1, 241, 1, 361, 241, 101]
Output 2:
    [2, 1]
*/
const int size=262144;
long long mp[size];
vector<int> Solution::solve(vector<char> &A, vector<string> &B) {
    long long query = A.size();
    memset(mp, 0, sizeof(mp));
    vector <int> res;
    for(int i=0; i<query; i++)
    {
        stringstream ss(B[i]);
        long long num, num1 = 0;
        ss >> num;
        for(int j=0; j<18; j++)
        {
            num1 = num1*2 + num%2;
            num=num/10;
        }
        if(A[i] == '+')
        {
            mp[num1]++;
        }
        else
        if(A[i] == '-')
        {
            mp[num1]--;
        }
        else
        if(A[i] == '?')
        {
            res.push_back(mp[num1]);
        }
    }
    return res;
}
