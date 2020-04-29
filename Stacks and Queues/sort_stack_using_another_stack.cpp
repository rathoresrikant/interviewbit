/*
Sort stack using another stack
Given a stack of integers A, sort it using another stack. Return the array of integers after sorting the stack using another stack.
Input Format
The only argument given is the integer array A.
Output Format
Return the array of integers after sorting the stack using another stack.
Constraints
1 <= length of the array <= 5000
0 <= A[i] <= 10^9
For Example
Input 1:
    A = [5, 4, 3, 2, 1]
Output 1:
    [1, 2, 3, 4, 5]

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    [5, 11, 17, 100]
*/
vector<int> Solution::solve(vector<int> &A) {
    vector <int> temp;
    int n = A.size();
    while(A.size() != 0)
    {
        int curr = A[A.size()-1];
        A.pop_back();
        while(temp.size() != 0 && temp[temp.size() - 1] > curr)
        {
            A.push_back(temp[temp.size()-1]);
            temp.pop_back();
        }
        temp.push_back(curr);
    }
    return temp;
}
