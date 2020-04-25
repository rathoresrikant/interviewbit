/*
Commutable Islands
There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it. We need to find bridges with minimal cost such that all islands are connected. It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other. Input Format:
The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
Output Format:
Return an integer representing the minimal cost required.
Constraints:
1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3
Examples:
Input 1:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 4]
            [1, 4, 3]
            [4, 3, 2]
            [1, 3, 10]  ]

Output 1:
    6

Explanation 1:
    We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

Input 2:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 2]
            [3, 4, 4]
            [1, 4, 3]   ]

Output 2:
    6

Explanation 2:
    We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.
*/
int Solution::solve(int A, vector<vector<int> > &B)
{
    priority_queue <pair<long long, int>, vector <pair<long long, int> >, greater<pair<long long, int> > >pq;
    vector <pair<long long, int>> adj[A+1];
    int n = B.size(), u, v, w;
    for(int i=0; i<n; i++)
    {
        u = B[i][0];
        v = B[i][1];
        w = B[i][2];
        adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
    }
    vector <int> visited(A+1,0);
    long long res = 0;
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        pair<long long, int> curr = pq.top();
        pq.pop();
        int x = curr.second;
        if(visited[x] == 1)
            continue;
        visited[x] = 1;
        res += curr.first;
        for(int i=0; i<adj[x].size(); i++)
        {
            int y = adj[x][i].second;
            if(visited[y] == 0)
                pq.push(adj[x][i]);
        }
    }
    return res;
}
