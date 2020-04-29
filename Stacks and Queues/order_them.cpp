/*
Order them
Problem Description
Given an array of integers A describing ranking of trucks. Your task is to insert these rank in another array B by some means of operations such that B is sorted in ascending order. For performing these operations you can use one stack C. In one Operation you can perform any of the following steps:
Remove the first element from A and append at the back of C.
Remove the last element from C and append at the back of B.
Remove the first element from A and append at the back of B.
you can perform these operations any number of times (possibly zero). Return 1 if B can be formed in ascending order using some operations else return 0.


Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= length of Array
All elements of A are distinct.


Input Format
The only argument given is the integer array A.


Output Format
Return 1 if B can be formed in ascending order using some operations else return 0.


Example Input
Input 1:
A = [5, 1, 2, 4, 3]
Input 2:
A = [5, 3, 1, 4, 2]



Example Output
Output 1:
1

0


Example Explanation
Explanation 1:
Given array A = [5, 1, 2, 4, 3], stack C = [] , array B = []
step 1: A = [5, 1, 2, 4, 3]
        C = []
        B = []
step 2: A = [1, 2, 4, 3]
        C = [5]
        B = []
step 3: A = [2, 4, 3]
        C = [5]
        B = [1]
step 4: A = [4, 3]
        C = [5]
        B = [1, 2]
step 5: A = [3]
        C = [5, 4]
        B = [1, 2]
step 6: A = []
        C = [5, 4]
        B = [1, 2, 3]
step 7: A = []
        C = [5]
        B = [1, 2, 3, 4]
step 8: A = []
        C = []
        B = [1, 2, 3, 4, 5]
Array B is in ascending order. So, return 1.
*/
int Solution::solve(vector<int> &A) {
    int n = A.size();
    stack <int> s;
    vector <int> B;
    for(int i=0; i<n; i++)
    {
        if(s.empty())
            s.push(A[i]);
        else
        if(A[i] < s.top())
            s.push(A[i]);
        else
        if(A[i] > s.top())
        {
            while(!s.empty() && s.top() < A[i] )
            {
                B.push_back(s.top());
                s.pop();
            }
            s.push(A[i]);
        }
    }
    while(!s.empty())
    {
        B.push_back(s.top());
        s.pop();
    }
    for(int i=1; i<n; i++)
    {
        if(B[i] < B[i-1])
            return 0;
    }
    return 1;
}
