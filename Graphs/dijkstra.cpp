/*
Dijsktra
Given a weighted undirected graph having A nodes and M weighted edges, and a source node C. You have to find an integer array D of size A such that:
=> D[i] : Shortest distance form the C node to node i.
=> If node i is not reachable from C then -1.
Note:
There are no self-loops in the graph.
No multiple edges between two pair of vertices.
The graph may or may not be connected.
Nodes are numbered from 0 to A-1.
Your solution will run on multiple testcases. If you are using global variables make sure to clear them.

Input Format
The first argument given is an integer A, representing the number of nodes.
The second argument given is the matrix B of size M x 3, where nodes B[i][0] and B[i][1] are connected with an edge of weight B[i][2].
The third argument given is an integer C.
Output Format
Return the integer array D.
Constraints
1 <= A <= 1e5
0 <= B[i][0],B[i][1] < A
0 <= B[i][2] <= 1e3;
0 <= C < A
For Example
Input 1:
    A = 6
    B = [   [0, 4, 9]
            [3, 4, 6]
            [1, 2, 1]
            [2, 5, 1]
            [2, 4, 5]
            [0, 3, 7]
            [0, 1, 1]
            [4, 5, 7]
            [0, 5, 1] ]
    C = 4
Output 1:
    D = [7, 6, 5, 6, 0, 6]

Input 2:
    A = 5
    B = [   [0, 3, 4]
            [2, 3, 3]
            [0, 1, 9]
            [3, 4, 10]
            [1, 3, 8]  ]
    C = 4
Output 2:
    D = [14, 18, 13, 10, 0]
*/
typedef pair<int,int> pi;
vector<int> Solution::solve(int A, vector<vector<int> > &B, int C)
{
    vector <pi> adj[A];
    int m = B.size(), u, v, w;
    for(int i=0; i<m; i++)
    {
        u = B[i][0], v = B[i][1], w = B[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector <int> dist(A, INT_MAX);
    dist[C] = 0;
    priority_queue <pi, vector<pi>, greater<pi>> pq;
    pq.push(make_pair(0, C));
    vector <bool> visited(A, false);
    while(!pq.empty())
    {
        pi curr = pq.top();
        pq.pop();
        w = curr.first, v = curr.second;
        if(visited[v] == true)
            continue;
        visited[v] = true;
        for(int i=0; i < adj[v].size(); i++)
        {
            int ver = adj[v][i].first, weight = adj[v][i].second;
            if(dist[v] + weight < dist[ver])
            {
                dist[ver] = dist[v] + weight;
                pq.push(make_pair(dist[ver], ver));
            }
        }
    }
    for(int i=0; i<A; i++)
    {
        if(dist[i] == INT_MAX)
            dist[i] = -1;
    }
    return dist;
}
