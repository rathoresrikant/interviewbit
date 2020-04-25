/*
Black Shapes
Given N x M character matrix A of O's and X's, where O = white, X = black.
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)
Input Format:
    The First and only argument is a N x M character matrix.
Output Format:
    Return a single integer denoting number of black shapes.
Constraints:
    1 <= N,M <= 1000
    A[i][j] = 'X' or 'O'
Example:
Input 1:
    A = [ OOOXOOO
          OOXXOXO
          OXOOOXO  ]
Output 1:
    3
Explanation:
    3 shapes are  :
    (i)    X
         X X
    (ii)
          X
    (iii)
          X
          X
Note: we are looking for connected shapes here.
XXX
XXX
XXX
is just one single connected black shape.
*/
int Solution::black(vector<string> &A) {
    int rows = A.size(), cols = A[0].length(), count = 0;
    if(rows == 0 && cols == 0)
        return 0;
    for(int i=0; i<rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(A[i][j] == 'X')
            {
                pair <int, int> start;
                start = make_pair(i,j);
                A[i][j] = 'O';
                queue <pair<int, int> > q;
                q.push(start);
                while(!q.empty())
                {
                    pair <int, int> curr = q.front();
                    q.pop();
                    int i1 = curr.first, j1 = curr.second;
                    if(i1-1 >= 0 && A[i1-1][j1] == 'X')
                    {
                        q.push(make_pair(i1-1,j1));
                        A[i1-1][j1] = 'O';
                    }
                    if(i1+1 < rows && A[i1+1][j1] == 'X')
                    {
                        q.push(make_pair(i1+1,j1));
                        A[i1+1][j1] = 'O';
                    }
                    if(j1+1 < cols && A[i1][j1+1] == 'X')
                    {
                        q.push(make_pair(i1, j1+1));
                        A[i1][j1+1] = 'O';
                    }
                    if(j1-1 >= 0 && A[i1][j1-1] == 'X')
                    {
                        q.push(make_pair(i1,j1-1));
                        A[i1][j1-1] = 'O';
                    }
                }
                count++;
            }
        }
    }
    return count;
}
