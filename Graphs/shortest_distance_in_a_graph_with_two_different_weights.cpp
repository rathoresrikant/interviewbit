/*
Shortest Distance in a graph with two different weights
Given a weighted undirected graph having A nodes, a source node C and destination node D. Find the shortest distance from C to D and if it is impossible to reach node D from C then return -1. You are expected to do it in Time Complexity of O(A + M). Note:
There are no self-loops in the graph.
No multiple edges between two pair of vertices.
The graph may or may not be connected.
Nodes are Numbered from 0 to A-1.
Your solution will run on multiple testcases. If you are using global variables make sure to clear them.

Input Format
The first argument given is an integer A, representing the number of nodes.
The second argument given is the matrix B, where B[i][0] and B[i][1] are connected through an edge of weight B[i][2].
The third argument given is an integer C, representing the source node.
The fourth argument is an integer D, representing the destination node.

Note: B[i][2] will be either 1 or 2.
Output Format
Return the shortest distance from C to D. If it is impossible to reach node D from C then return -1.
Constraints
1 <= A <= 1e5
0 <= B[i][0], B[i][1] < A
1 <= B[i][2] <= 2
0 <= C < A
0 <= D < A
For Example
Input 1:
    A = 6
    B = [   [2, 5, 1]
            [1, 3, 1]
            [0, 5, 2]
            [0, 2, 2]
            [1, 4, 1]
            [0, 1, 1] ]
    C = 3
    D = 2

Output 1:
    4

Explanation 1:
    The path to be followed will be:
        3 -> 1 (Edge weight : 1)
        1 -> 0 (Edge weight : 1)
        0 -> 2 (Edge weight : 2)
    Total length of path = 1 + 1 + 2 = 4.

Input 2:
    A = 5
    B = [   [0, 2, 1]
            [0, 4, 2]
            [1, 3, 1]
            [1, 4, 1]
            [0, 1, 1]
            [2, 4, 1]
            [3, 4, 2]
            [1, 2, 1]  ]
    C = 1
    D = 3

Output 2:
    1

Explanation 2:
    The path to be followed will be:
        1 -> 3 (Edge weight : 1)
    Total length of path = 1
*/
int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
    if(C == D)
        return 0;
    int m = B.size(), u, v, w;
    unordered_map <int, vector <int> > adj;
    for(int i=0; i<m; i++)
    {
        u = B[i][0], v = B[i][1], w = B[i][2];
        if(w == 1)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else
        {
            adj[u].push_back(A);
            adj[A].push_back(u);
            adj[A].push_back(v);
            adj[v].push_back(A);
            A++;
        }
    }
    queue <int> q;
    vector <bool> visited(A, false);
    vector <int> dist(A, 0);
    q.push(C);
    visited[C] = true;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int i=0; i<adj[curr].size(); i++)
        {
            int ver = adj[curr][i];
            if(visited[ver] == false)
            {
                q.push(ver);
                visited[ver] = true;
                dist[ver] = dist[curr] + 1;
            }
        }
    }
    if(dist[D] == 0)
        return -1;
    return dist[D];
}
