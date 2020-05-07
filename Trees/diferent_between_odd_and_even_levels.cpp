/*
Difference between odd and even levels
Given a binary tree of integers. Find the difference between the sum of nodes at odd level and sum of nodes at even level. Note: Consider the level of root node as 1. Constraints
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
    10
    Sum of nodes at odd level = 23
    Sum of ndoes at even level = 13

Input 2:
            1
           /  \
          2    10
           \
            4
Output 2:
    -7
    Sum of nodes at odd level = 5
    Sum of ndoes at even level = 12
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
int Solution::solve(TreeNode* A) {
    queue <TreeNode *> q;
    int level = 1, sum  = 0;
    q.push(A);
    while(!q.empty())
    {
        int m = q.size();
        while(m > 0)
        {
            TreeNode *curr = q.front();
            q.pop();
            if(level%2 == 1)
                sum += curr->val;
            else
                sum -= curr->val;
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
            m--;
        }
        level++;
    }
    return sum;
}
