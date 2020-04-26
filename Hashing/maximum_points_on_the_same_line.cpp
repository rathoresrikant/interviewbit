/*
Maximum Points on the same line
Given two array of integers A and B describing a pair of (A[i], B[i]) coordinates in 2-D plane. A[i] describe x coordinates of the ith point in 2D plane whereas B[i] describes the y-coordinate of the ith point in 2D plane. Find and return the maximum number of points which lie on the same line.
Input Format
The arguments given are integer arrays A and B.
Output Format
Return the maximum number of points which lie on the same line.
Constraints
1 <= (length of the array A = length of array B) <= 1000
-10^5 <= A[i], B[i] <= 10^5
For Example
Input 1:
    A = [-1, 0, 1, 2, 3, 3]
    B = [1, 0, 1, 2, 3, 4]
Output 1:
    4
    The maximum number of point which lie on same line are 4, those points are {0, 0}, {1, 1}, {2, 2}, {3, 3}

Input 2:
    A = [3, 1, 4, 5, 7, -9, -8, 6]
    B = [4, -8, -3, -2, -1, 5, 7, -4]
Output 2:
    2
*/
int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size(), res = 1;
    int y, x;
    if(n == 0)
        return 0;
    vector <vector <int> > arr(n, vector <int> (2));
    for(int i=0; i<n; i++)
    {
        arr[i][0] = A[i];
        arr[i][1] = B[i];
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++)
    {
        x = 0, y = 0;
        map<pair<int, int> , int> mp;
        pair<int, int> slope;
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] == arr[j])
                x++;
            int p = arr[j][0] - arr[i][0];
            int q = arr[j][1] - arr[i][1];
            if(p == 0 && q == 0)
                continue;
            slope = make_pair(p/__gcd(p,q), q/__gcd(p,q));
            mp[slope]++;
            y = max(mp[slope], y);
        }
        res = max(res, x + y + 1);
    }
    return res;
}
