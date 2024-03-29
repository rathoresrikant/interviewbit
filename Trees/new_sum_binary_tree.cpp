/*
2-Sum Binary Tree
Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K. Return 1 to denote that two such nodes exist. Return 0, otherwise. Notes
Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :
Input 1:

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2:

T:        10
         / \
        9   20

K = 40

Return: 0
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
void inorder(TreeNode *root, vector <int> &arr)
{
    if(root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}
int Solution::t2Sum(TreeNode* A, int B)
{
    vector <int> arr;
    inorder(A, arr);
    int n = arr.size();
    int left = 0, right = n-1;
    while(left < right)
    {
        if(arr[left] + arr[right] == B)
            return 1;
        else
        if(arr[left] + arr[right] < B)
            left++;
        else
            right--;
    }
    return 0;
}
