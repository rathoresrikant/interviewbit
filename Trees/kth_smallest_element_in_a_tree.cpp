/*
Symmetric Binary Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). Example :
    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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
int mirrorTree(TreeNode *root1, TreeNode *root2)
{
    if(root1 == NULL && root2 == NULL)
        return 1;
    if(root1 && root2 && root1->val == root2->val)
        return (mirrorTree(root1->left, root2->right) && mirrorTree(root1->right, root2->left));
    return false;
}
int Solution::isSymmetric(TreeNode* A) {
    return mirrorTree(A, A);
}
