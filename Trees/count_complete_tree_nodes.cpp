/*
Count Complete Tree Nodes
Given a complete binary tree, A, find the total number of nodes in the tree.
 Input Format:
The first and the only argument of input contains a reference to the root of the complete binary tree.
Output Format:
Return an integer representing the number of nodes in the complete binary tree.
Constraints:
1 <= Number of nodes in the binary tree <= 1e5
Examples:
Input 1:

        1
       / \
      2   3

Output 1:
    3

Input 2:

        1
       / \
      2   3
     / \
    4   5

Output 2:
    5
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
    if(A == NULL)
        return 0;
    else
        return solve(A->left) + 1 + solve(A->right);
}
