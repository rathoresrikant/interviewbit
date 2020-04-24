/*
Combination Sum II
Problem Description
Given an array of size N of candidate numbers A and a target number B. Return all unique combinations in A where the candidate numbers sums to B.  Each number in A may only be used once in the combination. Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
 Warning: DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS. Example : itertools.combinations in python. If you do, we will disqualify your submission and give you penalty points.


Problem Constraints
1 <= N <= 20


Input Format
First argument is an integer array A denoting the collection of candidate numbers.
Second argument is an integer which represents the target number.


Output Format
Return all unique combinations in A where the candidate numbers sums to B.


Example Input
Input 1:
A = [10, 1, 2, 7, 6, 1, 5]
B = 8



Example Output
Output 1:
[ [1 1 6 ]
  [1 2 5 ]
  [1 7 ]
  [2 6 ] ]



Example Explanation
Explanation 1:
 1 + 1 + 6 = 8
 1 + 2 + 5 = 8
 1 + 7 = 8
 2 + 6 = 8
 All the above combinations sum to 8 and are arranged in ascending order.
 */

 vector<vector<int> > Solution::combinationSum(vector<int> &arr, int B) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector <vector <int> > res;
    set <vector <int> > s;
    for(int i=0; i<pow(2,n); i++)
    {
        vector <int> temp;
        long sum = 0;
        for(int j=0; j<n; j++)
        {
            if((i&(1<<j)) != 0)
            {
                temp.push_back(arr[j]);
                sum += arr[j];
            }
        }
        int flag = 0;
        if(sum == B && s.find(temp) == s.end())
        {
            res.push_back(temp);
            s.insert(temp);
        }
    }
    return res;
}
