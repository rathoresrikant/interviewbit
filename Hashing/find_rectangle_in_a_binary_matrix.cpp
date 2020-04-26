/*
Find Rectangle in binary matrix
Given a binary matrix of integers A of size N x M consisting of only 0 or 1. you need to check whether there exists a square or rectangle in a square whose all four corners are 1. All four corners need to be distinct. If there exists such rectangle or square return 1, else return 0.
Input Format
The first argument given is the integer matrix A.
Output Format
 Return 1 if there exists such rectangle/square whose all four corners are 1 else return 0.
Constraints
1 <= N, M <= 200
0 <= A[i] <= 1
For Example
Input 1:
    A = [   [0, 1, 1]
            [0, 1, 1]
            [0, 1, 0]   ]
Output 1:
    1
    Explanation 1:
    [ [1, 1]
      [1, 1] ]
      There exists a square whose all corners are 1.

Input 2:
    A = [   [0, 1, 1]
            [0, 0, 1]
            [0, 1, 0]   ]
Output 2:
    0
*/
int Solution::solve(const vector<vector<int> > &A)
{
    int rows = A.size(), cols = A[0].size();
    unordered_map <int, unordered_set<int> > mp;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols-1; j++)
        {
            for(int k=j+1; k<cols; k++)
            {
                if(A[i][j] == 1 && A[i][k] == 1)
                {
                    if(mp.find(j) != mp.end() && mp[j].find(k) != mp[j].end())
                        return true;
                    mp[j].insert(k);
                }
            }
        }
    }
    return false;
}
