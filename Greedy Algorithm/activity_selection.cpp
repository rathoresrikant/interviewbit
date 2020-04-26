/*
Activity Selection
Given two integer arrays A and B of size N. There are N activities where A[i] denotes the start time of the ith activity and B[i] denotes the finish time of the ith activity. Your task is to select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.
Output Format
Return the maximum number of activities that can be performed by a single person.
Constraints
1 <= N <= 100000
0 <= A[i] <= B[i] <= 2*10^9
For Example
Input 1:
    A = [5, 1, 3, 0, 5, 8]
    B = [9, 2, 4, 6, 7, 9]
Output 1:
    4
    Explanation 1:
        Activites 2, 3, 5 and 6 can be selected (1- based indexing).

Input 2:
    A = [17, 8, 14, 24, 10, 8, 1, 30]
    B = [18, 45, 24, 27, 18, 10, 38, 35]
Output 2:
    4
*/
bool sortbysec(const pair<int, int> &a, const pair <int, int> &b)
{
    return (a.second < b.second);
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector <pair<int, int> > arr;
    for(int i=0; i<n; i++)
        arr.push_back(make_pair(A[i], B[i]));
    sort(arr.begin(), arr.end(), sortbysec);
    int count = 1, j = 0;
    for(int i=1; i<n; i++)
    {
        if(arr[i].first >= arr[j].second)
        {
            count++;
            j = i;
        }
    }
    return count;
}
