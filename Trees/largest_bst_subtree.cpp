/*
Largest BST Subtree
Problem Description
Given a Binary Tree A with N nodes. Write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). If the complete Binary Tree is BST, then return the size of whole tree. NOTE:
Largest subtree means subtree with most number of nodes.


Problem Constraints
1 <= N <= 105


Input Format
First and only argument is an pointer to root of the binary tree A.


Output Format
Return an single integer denoting the size of the largest subtree which is also a BST.


Example Input
Input 1:
     10
    / \
   5  15
  / \   \
 1   8   7
Input 2:
     5
    / \
   3   8
  / \ / \
 1  4 7  9


Example Output
Output 1:
 3
Output 2:
 7


Example Explanation
Explanation 1:
 Largest BST subtree is
                            5
                           / \
                          1   8
Explanation 2:
 Given binary tree itself is BST.

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
int size(TreeNode *root)
{
    if(root == NULL)
        return 0;
    return size(root->left) + 1 + size(root->right);
}
bool IsBST(TreeNode *root)
{
    if(root == NULL)
        return true;
    if(root->left && root->left->val > root->val)
        return false;
    if(root->right && root->right->val < root->val)
        return false;
    if(!IsBST(root->left) || !IsBST(root->right))
        return false;
    return true;
}
int Solution::solve(TreeNode* A)
{
    if(IsBST(A))
        return size(A);
    return max(solve(A->left), solve(A->right));
}
