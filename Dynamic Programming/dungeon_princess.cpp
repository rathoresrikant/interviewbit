/*
Dungeon Princess
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess. The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately. Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers). In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step. Write a function to determine the knight's minimum initial health so that he is able to rescue the princess. For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN. Dungeon Princess: Example 1
Input arguments to function: Your function will get an M*N matrix (2-D array) as input which represents the 2D grid as described in the question. Your function should return an integer corresponding to the knight's minimum initial health required.

 Note:
The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector <vector <int> > table(n+1, vector <int> (m+1));
    for(int i=0; i<n; i++)
        table[i][m] = INT_MAX;
    for(int i=0; i<m; i++)
        table[n][i] = INT_MAX;
    table[n][m-1] = 1;
    table[n-1][m] = 1;
    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            table[i][j] = max(1, min(table[i][j+1], table[i+1][j]) - A[i][j]);
        }
    }
    return table[0][0];
}
