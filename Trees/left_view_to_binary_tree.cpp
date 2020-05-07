/*
Left view of binary tree
Given a binary tree of integers. Return an array of integers representing the left view of the Binary tree. Left view of a Binary Tree is a set of nodes visible when the tree is visited from Left side Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= node values <= 10^9
For Example
Input 1:
            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8
Output 1:
    [1, 2, 4, 8]

Input 2:
            1
           /  \
          2    3
           \
            4
             \
              5
Output 2:
    [1, 2, 4, 5]
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    queue <TreeNode *> q;
    q.push(A);
    int m = 0;
    vector <int> res;
    while(!q.empty())
    {
        if(m == 0)
            res.push_back(q.front()->val);
        m = q.size();
        while(m != 0)
        {
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            m--;
        }
    }
    return res;
}
