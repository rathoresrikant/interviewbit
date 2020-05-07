/*
Min Depth of Binary Tree
Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 NOTE : The path has to end on a leaf node.
Example :
         1
        /
       2
min depth = 2.
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
int Solution::minDepth(TreeNode* A) {
    if(A == NULL)
        return 0;
    else
    if(!A->left && !A->right)
        return 1;
    else
    if(!A->left)
        return minDepth(A->right) + 1;
    else
    if(!A->right)
        return minDepth(A->left) + 1;
    else
    {
        int l = minDepth(A->left);
        int r = minDepth(A->right);
        return min(l, r) + 1;
    }
}
