/*
Word Ladder I
Problem Description
Given two words A and B, and a dictionary C, find the length of shortest transformation sequence from A to B, such that:
You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.
NOTE:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.



Problem Constraints
1 <= length(A), length(B), length(C[i]) <= 25
1 <= length(C) <= 5000


Input Format
The first argument of input contains a string, A. The second argument of input contains a string, B. The third argument of input contains an array of strings, C.


Output Format
Return an integer representing the minimum number of steps required to change string A to string B.


Example Input
Input 1:
 A = "hit"
 B = "cog"
 C = ["hot", "dot", "dog", "lot", "log"]
Input 2:
 A = "cat"
 B = "bat"
 C = ["rat"]
Input 3:
 A = "bait"
 B = "pant"
 C = ["a","b"]
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
