/*
BST nodes in a range
Given a binary search tree of integers. You are given a range [B, C]. Return the count of the number of nodes that lies in this range. Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= B < = C <= 10^9
For Example
Input 1:
            15
          /    \
        12      20
        / \    /  \
       10  14  16  27
      /
     8

     B = 12
     C = 20
Output 1:
    5

Input 2:
             8
            / \
           6  21
          / \
         1   4

        B = 2
        C = 20
Output 2:
    3

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
int Solution::solve(TreeNode* A, int B, int C)
{
    if(A == NULL)
        return 0;
    if(A->val == B and A->val == C)
        return 1;
    if(A->val >= B && A->val <= C)
        return 1 + solve(A->left, B, C) + solve(A->right, B, C);
    else
    if(A->val > C)
        return solve(A->left, B, C);
    else
    if(A->val < B)
        return solve(A->right, B, C);

}
