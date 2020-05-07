/*
Sorted Array To Balanced BST
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
Example :
Given A : [1, 2, 3]
A height balanced BST  :

      2
    /   \
   1     3
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
TreeNode* convert(const vector <int> &arr, int start, int end, int index)
{
    if(start > end)
        return NULL;
    TreeNode *temp = new TreeNode(arr[index]);
    temp->left = convert(arr, start, index-1, (start + index -1)/2);
    temp->right = convert(arr, index+1, end, (index+1+end)/2);
    return temp;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    if(n == 0)
        return NULL;
    return convert(A, 0, n-1, (n-1)/2);
}
