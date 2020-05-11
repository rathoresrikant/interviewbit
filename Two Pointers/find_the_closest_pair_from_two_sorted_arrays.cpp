/*
Find the closest pair from two sorted arrays
Problem Description
Given two sorted arrays of distinct integers, A and B, and an integer C, find and return the pair whose sum is closest to C and the pair has one element from each array. More formally, find A[i] and B[j] such that abs((A[i] + B[j]) - C) has minimum value. If there are multiple solutions find the one with minimum i and even if there are multiple values of j for the same i then return the one with minimum j. Return an array with two elements {A[i], B[j]}.


Problem Constraints
1 <= length of both the arrays <= 100000 1 <= A[i], B[i] <= 10s9 1 <= C <= 109


Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.
The third argument given is integer C.


Output Format
Return an array of size 2 denoting the pair which has sum closest to C.


Example Input
Input 1:
 A = [1, 2, 3, 4, 5]
 B = [2, 4, 6, 8]
 C = 9
Input 2:
 A = [5, 10, 20]
 B = [1, 2, 30]
 C = 13



Example Output
Output 1:
 [1, 8]
Output 2:
 [10, 2]



Example Explanation
Explanation 1:
 There are three pairs: (1, 8), (3, 6), (5, 4), that gives the minimum value.
 Since we have to return the value with minimum i and then with minimum j. We will return [1, 8].
Explanation 2:
 [10, 2] is the only pair such abs(10+2-13) is minimum.
 */

 vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    long long n = A.size(), m = B.size(), diff, res = INT_MAX, a, b, start, end;
    vector <int> ans;
    for(int i=0, j = m-1; i<n && j >=0;)
    {
        diff = abs(A[i] + B[j] - C);
        if(diff < res)
        {
            res = diff;
            a = A[i];
            b = B[j];
            start = i;
            end = j;
        }
        if(diff == res)
        {
            if(i < start)
            {
                a = A[i];
                b = B[j];
                start = i;
                end = j;
            }
            else
            if(i == start)
            {
                if(j < end)
                {
                    a = A[i];
                    b = B[j];
                    start = i;
                    end = j;
                }
            }
        }
        if(A[i] + B[j] < C)
        i++;
        else
        if(A[i] + B[j] > C)
        j--;
        else
        if(A[i] + B[j] == C)
        {
            a = A[i];
            b = B[j];
            break;
        }
    }
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}
