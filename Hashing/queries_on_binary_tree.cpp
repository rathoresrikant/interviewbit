/*
queries on binary tree
Problem Description
You have a complete binary tree consisting of 231-1 nodes rooted at 1. For each node i<230, left child is 2i and right child is 2i+1. For image visit: https://drive.google.com/file/d/15zq35WxWeNkDpZA9VY487sgIDGy2UTwq/view?usp=sharing you have to process Q queries of the form:
1 N D: increment value of each node in subtree rooted at N by D.
2 X 0: answer the value of node X
Note: initially, value of each node is 0.


Problem Constraints
1 <= N, X <= 2147483647
1 <= Q, D <= 46000


Input Format
First and only argument of input is a Q x 3 integer matrix A, where each row denote a query in above format.


Output Format
Return an integer array denoting answer of each type 2 query(in same order).


Example Input
Input 1:
    A = [[1, 1, 10], [1, 2, 5], [2, 3, 0], [2, 4, 0]]
Input 2:
    A = [[1, 3, 100], [1, 1451, 1452], [2, 34, 0]]

    Example Output
    Output 1:
    [10, 15]
    Output 2:
    [0]



    Example Explanation
    Explanation 1:
        First, all nodes under 1, increase value to 10.
        Then, nodes under 2, i.e 4, 5,... increase value to 15.
        value of node 3 is 10
        value of node 4 is 15
*/
vector<int> Solution::solve(vector<vector<int> > &A)
{
    unordered_map <long long, int> tree;
    int queries = A.size(), type, n, d;
    vector <int> res;
    for(int i=0; i<queries; i++)
    {
        type = A[i][0];
        n = A[i][1];
        d = A[i][2];
        if(type == 1)
        {
            tree[n] += d;
        }
        else
        {
            int sum = 0;
            while(n != 0)
            {
                sum += tree[n];
                n = n/2;
            }
            res.push_back(sum);
        }
    }
    return res;
}
