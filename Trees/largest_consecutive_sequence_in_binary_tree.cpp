/*
Longest Consecutive Sequence in Binary tree
Given a binary tree. Find the length of the longest path which comprises of nodes with consecutive values in increasing order. Every node is considered as a path of length 1. The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. Note: The longest consecutive path need to be from parent to child (cannot be the reverse). For Example
Input 1:
                2
               /  \
              3    1
             / \
            4  5
Output 1:
    3
    Explanation 1:
        Longest consecutive path is 2 - 3 - 4.

Input 2:
                2
                \
                 3
                /
               2
              /
              1
Output 2:
     2
     Explanation 2:
        Longest consecutive path is 2  - 3.
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
int Longest(TreeNode *child, TreeNode *parent, int len)
{
    if(child == NULL)
        return 0;
    if(parent != NULL && parent->val == child->val - 1)
        len += 1;
    else
        len = 1;
    return max(len, max(Longest(child->left, child, len), Longest(child->right, child, len)));
}
int Solution::solve(TreeNode* A)
{
    return Longest(A, NULL, 0);
}
