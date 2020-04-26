/*
Job Sequencing
Given two integer arrays A and B of size N. There are N jobs every job has a deadline and associated profit if the job is finished before the deadline. A[i] denotes the deadline of the ith job and B[i] denotes the associated profit with ith job. Every job takes single unit of time, so the minimum possible deadline for any job is 1. Your task is to schedule jobs such that maximum profit is achieved if only one job can be scheduled at a time.
Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.
Output Format
Return the maximum total profit.
Constraints
1 <= N <= 1000
1 <= A[i] <= 10^5
1 <= B[i] <= 10^6
For Example
Input 1:
    A = [2, 1, 2, 1, 3]
    B = [100, 19, 27, 25, 15]
Output 1:
    142
    Explanation 1:
         Schdedule 1st job at 1, profit = 100
         Schdedule 3rd job at 2, profit = 27
         Schdedule 5th job at 3, profit = 15
         Total Profit = 100 + 27 + 15 = 142.

Input 2:
    A = [9, 1, 9, 7, 5, 1, 9, 7, 5, 6, 5]
    B = [9, 3, 30, 43, 10, 10, 7, 18, 34, 4, 41]
Output 2:
    202
*/
bool sortbysec(const pair <int, int> &a, const pair <int, int> &b)
{
    return (a.second > b.second);
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size(), res = 0, deadline;
    vector <pair <int, int> >arr;
    for(int i=0; i<n; i++)
        arr.push_back(make_pair(A[i], B[i]));
    sort(arr.begin(), arr.end(), sortbysec);
    vector <bool> slot(n, true);
    for(int i=0; i<n; i++)
    {
        deadline = arr[i].first;
        while(slot[deadline] ==false)
            deadline--;
        if(deadline > 0)
        {
            slot[deadline] = false;
            res += arr[i].second;
        }
    }
    return res;
}
