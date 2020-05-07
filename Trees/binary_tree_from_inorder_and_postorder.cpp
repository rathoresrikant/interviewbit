/*
Binary Tree From Inorder And Postorder
Given inorder and postorder traversal of a tree, construct the binary tree.
 Note: You may assume that duplicates do not exist in the tree.
Example :
Input :
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return :
            1
           / \
          2   3
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

TreeNode *Build(vector <int> &inorder, vector <int> &postorder, int ps, int pe, int is, int ie)
{
    if(ps > pe || is > ie)
        return NULL;
    TreeNode *curr = new TreeNode(postorder[pe]);
    int idx = 0;
    for(int i=is; i<=ie; i++)
    {
        if(inorder[i] == curr->val)
        {
            idx = i;
        }
    }
    curr->left = Build(inorder, postorder, ps, pe - ie + idx -1, is, idx - 1);
    curr->right = Build(inorder, postorder, pe - ie + idx, pe - 1, idx + 1, ie);
    return curr;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B)
{
    int pe = B.size(), ie = A.size();
    return Build(A, B, 0, pe-1, 0, ie-1);
}
