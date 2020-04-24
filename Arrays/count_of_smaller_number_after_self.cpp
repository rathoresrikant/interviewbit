/*
Count of smaller numbers after self
Problem Description
Given an array of integers A, find and return new integer array B. Array B has the property where B[i] is the number of smaller elements to the right of A[i].


Problem Constraints
1 <= length of the array <= 100000 1 <= A[i] <= 109


Input Format
The only argument given is the integer array A.


Output Format
Return the new integer array B.


Example Input
A = [1, 5, 4, 2, 1]


Example Output
[0, 3, 2, 1, 0]


Example Explanation
Number of smaller elements to the right of 1 are 0.
Number of smaller elements to the right of 5 are 3 (4, 2, 1).
Number of smaller elements to the right of 4 are 2 (2, 1).
Number of smaller elements to the right of 2 are 1 (1).
Number of smaller elements to the right of 1 are 0.
*/

vector <pair<int, int> > mergeSort(vector <pair<int, int> > arr, vector <int > &res, int n)
{
    if(arr.size() == 1)
        return arr;
    int mid = n/2;
    vector <pair <int, int> > left = mergeSort(vector <pair<int, int> > (arr.begin(), arr.begin() + mid), res, mid);
    vector <pair <int, int> > right = mergeSort(vector <pair<int, int> > (arr.begin() + mid, arr.end()), res, n - mid);
    int i = 0, j = 0, k = 0;
    while(i <left.size() && j < right.size())
    {
        if(left[i].first <= right[j].first)
        {
            res[left[i].second] += j;
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while(i < left.size())
    {
        res[left[i].second] += j;
        arr[k++] = left[i++];
    }
    while(j < right.size())
    {
        arr[k++] = right[j++];
    }
    return arr;
}
vector<int> Solution::solve(vector<int> &A)
{
    vector <pair <int, int> > arr;
    vector <int> res;
    int n = A.size();
    for(int i=0; i<n; i++)
    {
        arr.push_back(make_pair(A[i], i));
        res.push_back(0);
    }
    mergeSort(arr, res, arr.size());
    return res;
}
