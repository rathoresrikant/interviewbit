/*
Meeting rooms
Given an array of array of integers A of size N x 2 denoting time intervals of different meetings. Where: A[i][0] = start time of the ith meeting. A[i][1] = end time of the ith meeting. find the minimum number of conference rooms required so that all meetings can be done.
Input Format
The only argument given is the matrix A.
Output Format
Return the minimum number of conference rooms required so that all meetings can be done.
Constraints
1 <= N <= 100000
0 <= A[i][0] < A[i][1] <= 2 * 10^9
For Example
Input 1:
    A = [   [0, 30]
            [5, 10]
            [15, 20] ]
Output 1:
    2
    Meeting one can be done in conference room 1 form 0 - 30.
    Meeting two can be done in conference room 2 form 5 - 10.
    Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.

Input 2:
   A =  [   [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13] ]
Output 2:
    4
    Meeting one can be done in conference room 1 from 1 - 18.
    Meeting five can be done in conference room 2 from 2 - 11.
    Meeting four can be done in conference room 3 from 4 - 15.
    Meeting six can be done in conference room 4 from 5 - 13.
    Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
    Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.
*/
int Solution::solve(vector<vector<int> > &A) {
    vector <pair<int, int> > arr;
    int n = A.size();
    for(int i=0; i<n; i++)
        arr.push_back(make_pair(A[i][0], A[i][1]));
    sort(arr.begin(), arr.end());
    priority_queue <int, vector <int>, greater<int>> pq;
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(pq.empty())
        {
            pq.push(arr[i].second);
            count++;
        }
        else
        {
            if(arr[i].first >= pq.top())
            {
                pq.pop();
            }
            else
            {
                count++;
            }
            pq.push(arr[i].second);
        }
    }
    return count;
}
