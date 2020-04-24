/*
Alternate positive and negative elements
Problem Description
Given an array of integers A, arrange them in an alternate fashion such that every non-negative number is followed by negative and vice-versa, starting from a negative number, maintaining the order of appearance. The number of non-negative and negative numbers need not be equal. If there are more non-negative numbers they appear at the end of the array. If there are more negative numbers, they too appear at the end of the array. Note: Try solving with O(1) extra space.


Problem Constraints
1 <= length of the array <= 7000
-10^9 <= A[i] <= 109


Input Format
The first argument given is the integer array A.


Output Format
Return the modified array.


Example Input
Input 1:
A = [-1, -2, -3, 4, 5]
Input 2:
A = [5, -17, -100, -11]



Example Output
Output 1:
[-1, 4, -2, 5, -3]
Output 2:
[-17, 5, -100, -11]



Example Explanation
Explanation 1:
A = [-1, -2, -3, 4, 5]
Move 4 in between -1 and -2, A => [-1, 4, -2, -3, 5]
Move 5 in between -2 and -3, A => [-1, 4, -2, 5, -3]
*/

vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector <int> pos, neg;
    for(int i=0; i < n; i++)
    {
        if(A[i] < 0)
            neg.push_back(A[i]);
        if(A[i] >= 0)
            pos.push_back(A[i]);
    }
    int k = 0, l = 0, i = 0;
    vector <int> res(n);
    while(i < n)
    {
        if(k == neg.size() || l == pos.size())
            break;
        if(i%2 == 0)
        {
            res[i] = neg[k];
            k++;
        }
        else
        {
            res[i] = pos[l];
            l++;
        }
        i++;
    }
    while(k < neg.size())
    {
        res[i] = neg[k];
        k++;
        i++;
    }
    while(l < pos.size())
    {
        res[i] = pos[l];
        l++;
        i++;
    }
    return res;
}
